#include "naointerface.h"

using namespace IAL;

NaoInterface::NaoInterface(boost::shared_ptr<AL::ALBroker> broker,
                           const std::string &name):
    AL::ALModule(broker, name)
{
    setModuleDescription("Inteface to NAO important functionality.");

    mBallDetector = new BallDetector(broker);
}

NaoInterface::~NaoInterface()
{
    mBallDetector->stopDetection();
}

void NaoInterface::init()
{
    mBallDetector->startDetection();
}
