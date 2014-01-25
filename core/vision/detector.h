#ifndef DETECTOR_H
#define DETECTOR_H

#include <alproxies/alvideodeviceproxy.h>
#include <alproxies/almemoryproxy.h>
#include <althread/almutex.h>

#include <qi/os.hpp>

#include <opencv2/core/core.hpp>


namespace IAL
{
    class Detector
    {
    public:
        Detector(boost::shared_ptr<AL::ALBroker> broker);

        virtual ~Detector();

        // Start detection
        virtual void startDetection();

        // Stop detection
        virtual void stopDetection();

    protected:
        void getImage(const std::string subscriberId, cv::Mat * imageHeader);

        // Flag for detection
        bool mIsDetecting;

        // Memory proxy for event subscription and data access.
        AL::ALMemoryProxy mMemoryProxy;

        // Proxy to video device.
        AL::ALVideoDeviceProxy mALVideoDevice;

        // Video subscriber id.
        std::string mTSubscriberId;
        std::string mBSubscriberId;

        // Video framerate.
        int mFramerate;

        // Mutex to make the callback function thread-safe.
        boost::shared_ptr<AL::ALMutex> mCallbackMutex;

        // Thread object.
        pthread_t mProcessThread;

        AL::ALValue mImage;

        qi::os::timeval mCurrentTime;


        // Get the time in Us
        // @return time in Us
        static long long getTime(void * arg);
    };
}

#endif // DETECTOR_H
