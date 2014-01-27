#include "naointerface.h"

using namespace IAL;

NaoInterface::NaoInterface(boost::shared_ptr<AL::ALBroker> broker,
                           const std::string &name):
    AL::ALModule(broker, name)
{
    setModuleDescription("Inteface to NAO important functionality.");

    // Bindings
    functionName("startBallDetection", getName(), "Starts ball detection.");
    addMethodExample("python",
        "# Starts ball detection\n"
        "naointefaceProxy = ALProxy(\"IAL::NaoInterface\", \"127.0.0.1\", 9559)\n"
        "naointefaceProxy.startBallDetection()\n"
    );
    addParam("trackingOn", "Turn on tracking of the ball. Defaults to false.");
    BIND_METHOD(NaoInterface::startBallDetection);

    functionName("stopDetection", getName(), "Stops ball detection.");
    addMethodExample("python",
        "# Starts ball detection\n"
        "naointefaceProxy = ALProxy(\"IAL::NaoInterface\", \"127.0.0.1\", 9559)\n"
        "naointefaceProxy.stopBallDetection()\n"
    );
    BIND_METHOD(NaoInterface::stopBallDetection);

    functionName("startBallTracking", getName(), "Starts ball tracking.");
    addMethodExample("python",
        "# Starts ball tracking\n"
        "naointefaceProxy = ALProxy(\"IAL::NaoInterface\", \"127.0.0.1\", 9559)\n"
        "naointefaceProxy.startBallTracking()\n"
    );
    BIND_METHOD(NaoInterface::startBallTracking);

    functionName("stopBallTracking", getName(), "Stops ball tracking.");
    addMethodExample("python",
        "# Stops ball tracking\n"
        "naointefaceProxy = ALProxy(\"IAL::NaoInterface\", \"127.0.0.1\", 9559)\n"
        "naointefaceProxy.stopBallTracking()\n"
    );
    BIND_METHOD(NaoInterface::stopBallTracking);

    mBallDetector = new BallDetector(broker);
}

NaoInterface::~NaoInterface()
{
    stopBallDetection();
}

void NaoInterface::init()
{
    startBallDetection();
}

void NaoInterface::startBallDetection(const bool & trackingOn)
{
    mBallDetector->startDetection(trackingOn);
}

void NaoInterface::stopBallDetection()
{
    mBallDetector->stopDetection();
}

void NaoInterface::startBallTracking()
{
    mBallDetector->startTracking();
}

void NaoInterface::stopBallTracking()
{
    mBallDetector->stopTracking();
}
