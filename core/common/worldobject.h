#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "enums.h"

#include <boost/shared_ptr.hpp>

#include <qi/os.hpp>


namespace IAL
{
    class WorldObject;
    typedef boost::shared_ptr<WorldObject> WorldObject_ptr;


    class WorldObject
    {
    public:
        WorldObject();
        virtual ~WorldObject()   {}

        virtual WorldObjectType getType()   { return WORLD_OBJECT_INVALID; }

        void setImageCenter(int x, int y)               { mImageCenterX = x; mImageCenterY = y; }
        void setImageRadius(int radius)                 { mImageRadius = radius; }
        void setCameraId(CameraId cameraId)             { mCameraId = cameraId; }
        void setSeen(bool seen)                         { mSeen = seen; }
        void setTimestamp(qi::os::timeval timestamp)    { mTimestamp = timestamp; }

        int getImageCenterX()           { return mImageCenterX; }
        int getImageCenterY()           { return mImageCenterY; }
        int getImageRadius()            { return mImageRadius; }
        int getCameraId()               { return mCameraId; }
        bool isSeen()                   { return mSeen; }
        qi::os::timeval getTimeStamp()  { return mTimestamp; }

        virtual void reset();
        virtual void copy(WorldObject_ptr object);

    private:
//        Point2D mLoc;

        int mImageCenterX;
        int mImageCenterY;
        int mImageRadius;

        bool mCameraId;

        bool mSeen;

        qi::os::timeval mTimestamp;
    };
}

#endif // WORLDOBJECT_H
