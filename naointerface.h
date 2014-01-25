#ifndef NAOINTERFACE_H
#define NAOINTERFACE_H

#include "core/vision/balldetector.h"

#include <alcommon/almodule.h>


namespace AL
{
    // This is a forward declaration of AL:ALBroker which
    // avoids including <alcommon/albroker.h> in this header
    class ALBroker;
}


namespace IAL
{
    class NaoInterface : public AL::ALModule
    {
    public:
        NaoInterface(boost::shared_ptr<AL::ALBroker> broker,
                     const std::string &name);

        virtual ~NaoInterface();

        virtual void init();

    private:
        BallDetector * mBallDetector;
    };
}

#endif // NAOINTERFACE_H
