#include "worldobject.h"

using namespace IAL;


WorldObject::WorldObject():
    mSeen(false)
{
}

void WorldObject::reset()
{
    mSeen = false;
}

void WorldObject::copy(WorldObject_ptr object)
{
//    mLoc = object->getLoc();

    mCameraId = object->getCameraId();  
    mSeen = object->isSeen();
    mTimestamp = object->getTimeStamp();
}

void WorldObject::setLoc(float distance, float bearing)
{
//    distance = distance / 1000.0f;
    mLoc.x = cos(bearing) * distance;
    mLoc.y = sin(bearing) * distance;
}
