#include "balldetector.h"

#include "../common/imageconstants.h"
#include "../common/worldobjectmanager.h"

#include <alerror/alerror.h>

#include <althread/alcriticalsection.h>
#include <alvision/alvisiondefinitions.h>

// OpenCV includes.
#include <opencv2/imgproc/imgproc.hpp>

#include <cmath>

#include <qi/os.hpp>
#include <qi/log.hpp>


using namespace IAL;

BallDetector::BallDetector(boost::shared_ptr<AL::ALBroker> broker):
    Detector(broker)
{
#ifdef DEBUG
    mDebugger = new DebugBallDetector();
#endif
}

BallDetector::~BallDetector()
{
#ifdef DEBUG
    if (mDebugger != NULL)
        delete mDebugger;
    mDebugger = NULL;
#endif
}

void BallDetector::startDetection(bool trackingOn)
{
    Detector::startDetection(trackingOn);

    try
    {
        // Subscribe a client image requiring 320*240 and BGR colorspace.
        mBSubscriberId = mALVideoDevice.subscribeCamera("BallDetector", CAMERA_BOTTOM, AL::kQVGA, AL::kBGRColorSpace, mFramerate);
        mTSubscriberId = mALVideoDevice.subscribeCamera("BallDetector", CAMERA_TOP, AL::kQVGA, AL::kBGRColorSpace, mFramerate);

        mIsDetecting = true;
        pthread_create(&mProcessThread, 0, processThread, this);
    }
    catch (const std::exception & e)
    {
        qiLogError("BallDetector") << e.what() << std::endl;
        mIsDetecting = false;
    }
}

void BallDetector::stopDetection()
{
    Detector::stopDetection();

    void * retVal;
    pthread_join(mProcessThread, &retVal);

    try
    {
        mALVideoDevice.unsubscribe(mTSubscriberId);
        mALVideoDevice.unsubscribe(mBSubscriberId);
    }
    catch (const std::exception & e)
    {
        qiLogError("BallDetector") << e.what() << std::endl;
    }
}

bool BallDetector::findBall(const std::string subscriberId, cv::Scalar minThreshold, cv::Scalar maxThreshold, cv::Mat * imageHeader, Ball_ptr & ball)
{
    bool ballFound = false;

    getImage(subscriberId, imageHeader);

    // Change the color format from BGR to HSV
    cv::Mat imgHSV;
    cv::cvtColor(*imageHeader, imgHSV, CV_BGR2HSV);

    // Filter out colors which are out of range
    cv::Mat thresholded;
    cv::inRange(imgHSV, minThreshold, maxThreshold, thresholded);

#ifdef DEBUG
    mDebugger->calibrate(&imgHSV);
//    minThreshold = mDebugger->getMinThreshold();
//    maxThreshold = mDebugger->getMaxThreshold();
#endif

    // Smooth the binary image
    GaussianBlur(thresholded, thresholded, cv::Size(9, 9), -1, -1);

    std::vector<cv::Vec3f> circles;
    HoughCircles(thresholded, circles, CV_HOUGH_GRADIENT, 2, thresholded.rows/4, 100, 50);

    for( size_t i = 0; i < circles.size(); i++ )
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
//        qiLogInfo("BallDetector") << "center=(" << center.x << "," << center.y << ")" << std::endl;

        float imageX = static_cast<float>(center.x);
        float imageY = static_cast<float>(center.y);
        ball->setSeen(true);
        ball->setImageCenter(imageX, imageY);
        ball->setImageRadius(radius);

        float yaw = atan((IMAGE_WIDTH / 2.0f - imageX) / (IMAGE_WIDTH / (2.0f * tan(HFOV / 2.0f))));
        float pitch = atan((IMAGE_HEIGHT / 2.0f - imageY) / (IMAGE_HEIGHT / (2.0f * tan(VFOV / 2.0f))));

        ball->setDistance(pitch);
        ball->setLoc(ball->getDistance(), yaw);

#ifdef DEBUG
        mDebugger->drawCircle(imageHeader, center, radius);
        mDebugger->writeText(imageHeader, "distance=", ball->getDistance(), 30, 30);
        mDebugger->writeText(imageHeader, "loc.x=", ball->getLoc().x, 30, 45);
        mDebugger->writeText(imageHeader, "loc.y=", ball->getLoc().y, 30, 60);
#endif

        if (mTrackingOn)
            trackBall(pitch, yaw);

        ballFound = true;
        break;      // TODO: need logic to determine the best fit for ball
    }

    return ballFound;
}

void BallDetector::trackBall(float pitch, float yaw)
{
    // center ball in image
    bool isAbsolute = false;
    AL::ALValue names = AL::ALValue::array("HeadYaw", "HeadPitch");
    mMotionProxy.stiffnessInterpolation("Head", 0.6f, 1.0f);
    AL::ALValue angleLists = AL::ALValue::array(yaw, -pitch);
    AL::ALValue timeLists = AL::ALValue::array(1.0f, 1.0f);
    mMotionProxy.angleInterpolation(names, angleLists, timeLists, isAbsolute);
    qi::os::sleep(1.0f);
}


void * BallDetector::processThread(void * arg)
{
    BallDetector * self = (BallDetector *)arg;

    // Time measurement
    long long bufferTime = getTime(arg);
    long long lastBufferTime = bufferTime;

    // Buffer duration depends on framerate
    long long duration = 1000000000 / self->mFramerate; // in nanoseconds

    // cv::Mat header to wrap an OpenCV image.
    cv::Mat imageHeaderTop = cv::Mat(cv::Size(IMAGE_WIDTH, IMAGE_HEIGHT), CV_8UC3);
    cv::Mat imageHeaderBottom = cv::Mat(cv::Size(IMAGE_WIDTH, IMAGE_HEIGHT), CV_8UC3);

    // Determined by calibration
    int min1 = 2, min2 = 15, min3 = 9;
    int max1 = 82, max2 = 260, max3 = 260;

    cv::Scalar minThreshold = cv::Scalar(min1, min2, min3, 0);
    cv::Scalar maxThreshold = cv::Scalar(max1, max2, max3, 0);

    Ball_ptr ball(new Ball);

    bool topBallFound = false;
    bool bottomBallFound = false;

#ifdef DEBUG
    self->mDebugger->init(CAMERA_BOTH);
#endif

    try
    {
        while(self->mIsDetecting)
        {
            bufferTime = getTime(arg);
            if((bufferTime - lastBufferTime) < duration / 1000)
            {
                qi::os::msleep(10);
                continue;
            }

            ball->reset();
            ball->setCameraId(CAMERA_BOTTOM);

            bottomBallFound = self->findBall(self->mBSubscriberId, minThreshold, maxThreshold, &imageHeaderBottom, ball);

#ifdef DEBUG
            if (self->mDebugger->show(CAMERA_BOTTOM, &imageHeaderBottom))
                break;
#endif
            // Prefer the ball from the bottom camera if available
            if (!bottomBallFound)
            {
                ball->reset();
                ball->setCameraId(CAMERA_TOP);

                topBallFound = self->findBall(self->mTSubscriberId, minThreshold, maxThreshold, &imageHeaderTop, ball);

#ifdef DEBUG
                if (self->mDebugger->show(CAMERA_TOP, &imageHeaderTop))
                    break;
#endif
            }

            if (bottomBallFound || topBallFound)
            {
                Ball_ptr gameBall = boost::static_pointer_cast<Ball>(WorldObjectManager::getInstance().getWorldObject(WORLD_OBJECT_BALL));
                gameBall->copy(ball);
                gameBall->setTimestamp(self->mCurrentTime);
//                self->mMemoryProxy.raiseEvent("ballDetected", self->mBall);
            }

            lastBufferTime = bufferTime;
        }
    }
    catch (const std::exception &error)
    {
        qiLogError("BallDetector") << "process loop stopped, reason: " << error.what() << std::endl;
        if (self->mIsDetecting)
            self->stopDetection();
    }

    return 0;
}
