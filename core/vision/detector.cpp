#include "detector.h"

#include <iostream>
#include <alerror/alerror.h>

#include <qi/os.hpp>


using namespace IAL;

Detector::Detector(boost::shared_ptr<AL::ALBroker> broker):
    mIsDetecting(false),
    mTrackingOn(false),
    mMemoryProxy(broker),
    mALVideoDevice(broker),
    mMotionProxy(broker),
    mTSubscriberId(),
    mBSubscriberId(),
    mFramerate(30),
    mCallbackMutex(AL::ALMutex::createALMutex()),
    mProcessThread()
{
}

Detector::~Detector()
{
    stopDetection();
}


void Detector::startDetection(bool trackingOn)
{
    if (mIsDetecting)
        throw std::runtime_error("Detection already started");

    mTrackingOn = trackingOn;
}

void Detector::stopDetection()
{
    mTrackingOn = false;
    mIsDetecting = false;
}


void Detector::getImage(const std::string subscriberId, cv::Mat * imageHeader)
{
//    Detector * self = (Detector *)arg;

    // Get an image and its metadata from video device
    mImage = mALVideoDevice.getImageRemote(subscriberId);
    imageHeader->data = (uchar *)mImage[6].GetBinary();

    // Releasing the image for video device
    mALVideoDevice.releaseImage(subscriberId);
}

long long Detector::getTime(void * arg)
{
    Detector * self = (Detector *)arg;

    qi::os::gettimeofday(&self->mCurrentTime);
    long long time = (long long)self->mCurrentTime.tv_sec * 1000000;    // seconds
    time += (long long)self->mCurrentTime.tv_usec;                      // microseconds
    return time;
}
