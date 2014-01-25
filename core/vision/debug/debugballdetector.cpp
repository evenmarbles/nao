#include "debugballdetector.h"

#ifdef DEBUG

// OpenCV includes.
#include <opencv2/highgui/highgui.hpp>

#include <qi/log.hpp>


using namespace IAL;

DebugBallDetector::DebugBallDetector():
    mCalibrate(false),
    mMin1(27),
    mMax1(56),
    mMin2(4),
    mMax2(46),
    mMin3(193),
    mMax3(260)

{
}

DebugBallDetector::DebugBallDetector(bool calibrate, int min1, int max1, int min2, int max2, int min3, int max3):
    mCalibrate(calibrate),
    mMin1(min1),
    mMax1(max1),
    mMin2(min2),
    mMax2(max2),
    mMin3(min3),
    mMax3(max3)

{
}

void DebugBallDetector::init(CameraId camId)
{
    // Create a OpenCV window to display the images.
    if (camId == CAMERA_TOP || camId == CAMERA_BOTH)
        cv::namedWindow("imageCamTop");
    if (camId == CAMERA_BOTTOM || camId == CAMERA_BOTH)
        cv::namedWindow("imageCamBottom");

    if (mCalibrate)
    {
        cv::namedWindow("F1", CV_WINDOW_AUTOSIZE);
        cv::namedWindow("F2", CV_WINDOW_AUTOSIZE);
        cv::namedWindow("F3", CV_WINDOW_AUTOSIZE);
        cv::namedWindow("imgHSV", CV_WINDOW_AUTOSIZE);

        char trackbarName1[50]="min1";
        char trackbarName2[50]="max1";
        char trackbarName3[50]="min2";
        char trackbarName4[50]="max2";
        char trackbarName5[50]="min3";
        char trackbarName6[50]="max3";

        cv::createTrackbar(trackbarName1, "F1", &mMin1, 260, NULL);
        cv::createTrackbar(trackbarName2, "F1", &mMax1, 260, NULL);
        cv::createTrackbar(trackbarName3, "F2", &mMin2, 260, NULL);
        cv::createTrackbar(trackbarName4, "F2", &mMax2, 260, NULL);
        cv::createTrackbar(trackbarName5, "F3", &mMin3, 260, NULL);
        cv::createTrackbar(trackbarName6, "F3", &mMax3, 260, NULL);

        mMinThreshold = cv::Scalar(mMin1, mMin2, mMin3, 0);
        mMaxThreshold = cv::Scalar(mMax1, mMax2, mMax3, 0);
    }
}

void DebugBallDetector::calibrate(cv::Mat * imgHSV)
{
    if (mCalibrate)
    {
        mMinThreshold = cv::Scalar(mMin1, mMin2, mMin3, 0);
        mMaxThreshold = cv::Scalar(mMax1, mMax2, mMax3, 0);

        std::vector<cv::Mat> layers;
        cv::split(*imgHSV, layers);

        cv::inRange(layers[0], cv::Scalar(mMin1,0,0,0), cv::Scalar(mMax1,0,0,0), layers[0]);
        cv::inRange(layers[1], cv::Scalar(mMin1,0,0,0), cv::Scalar(mMax1,0,0,0), layers[1]);
        cv::inRange(layers[2], cv::Scalar(mMin1,0,0,0), cv::Scalar(mMax1,0,0,0), layers[2]);

        cv::imshow("F1", layers[0]);
        cv::imshow("F2", layers[1]);
        cv::imshow("F3", layers[2]);
        cv::imshow("imgHSV" , *imgHSV);
    }
}

void DebugBallDetector::drawCircle(cv::Mat * imageHeader, cv::Point center, int radius)
{
    // draw the circle center
    cv::circle(*imageHeader, center, 3, cv::Scalar(0,255,0), -1, 8, 0);
    // draw the circle outline
    cv::circle(*imageHeader, center, radius, cv::Scalar(0,0,255), 2, 8, 0);
}

bool DebugBallDetector::show(CameraId camId, cv::Mat * imageHeader)
{
    // Display the image on screen
    if (camId == CAMERA_TOP)
        cv::imshow("imageCamTop", *imageHeader);
    else if (camId == CAMERA_BOTTOM)
        cv::imshow("imageCamBottom", *imageHeader);

    //If ESC key pressed, Key=0x10001B under OpenCV 0.9.7(linux version),
    //remove higher bits using AND operator
    if( (cvWaitKey(10) & 255) == 27 )
    {
        return true;
    }
    return false;
}

#endif
