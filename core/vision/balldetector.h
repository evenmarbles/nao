#ifndef BALLDETECTOR_H
#define BALLDETECTOR_H

#include "detector.h"

#include "../common/ball.h"

#ifdef DEBUG
# include "debug/debugballdetector.h"
#endif

#include <pthread.h>


namespace IAL
{
    class BallDetector : public Detector
    {
    public:
        BallDetector(boost::shared_ptr<AL::ALBroker> broker);

        ~BallDetector();

        // Start ball detection
        virtual void startDetection(bool trackingOn);

        // Stop ball detection
        virtual void stopDetection();

    private:
        bool findBall(const std::string subscriberId,
                      cv::Scalar minThreshold, cv::Scalar maxThreshold,
                      cv::Mat * imageHeader, Ball_ptr & ball);

        void trackBall(float pitch, float yaw);

#ifdef DEBUG
        DebugBallDetector * mDebugger;
#endif

        // Image acquisition loop
        // @param arg user data (the module instance)
        // @return Thread return value
        static void * processThread(void * arg);
    };
}

#endif // BALLDETECTOR_H
