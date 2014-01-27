#ifndef DEBUGBALLDETECTOR_H
#define DEBUGBALLDETECTOR_H

#ifdef DEBUG
#include "../../common/enums.h"

#include <opencv2/core/core.hpp>


namespace IAL
{
    class DebugBallDetector
    {
    public:
        DebugBallDetector();
        DebugBallDetector(bool calibrate, int mMin1, int mMax1, int mMin2, int mMax2, int mMin3, int mMax3);
        ~DebugBallDetector() {}


        void setCalibrate(bool calibrate) { mCalibrate = calibrate; }

        cv::Scalar getMinThreshold()      { return mMinThreshold; }
        cv::Scalar getMaxThreshold()      { return mMaxThreshold; }


        void init(CameraId camId);

        void calibrate(cv::Mat * imgHSV);

        void drawCircle(cv::Mat * imageHeader, cv::Point center, int radius);
        void writeText(cv::Mat * imageHeader, std::string name, float value, int posX, int posY);

        bool show(CameraId camId, cv::Mat * imageHeader);

    private:
        bool mCalibrate;

        int mMin1;
        int mMax1;

        int mMin2;
        int mMax2;

        int mMin3;
        int mMax3;

        cv::Scalar mMinThreshold;
        cv::Scalar mMaxThreshold;
    };
}
#endif

#endif // DEBUGBALLDETECTOR_H
