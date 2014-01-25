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

    mImageCenterX = object->getImageCenterX();
    mImageCenterY = object->getImageCenterY();
    mImageRadius = object->getImageRadius();

    mCameraId = object->getCameraId();

    mSeen = object->isSeen();

    mTimestamp = object->getTimeStamp();
}
