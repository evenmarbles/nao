#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <boost/shared_ptr.hpp>

#include <qi/os.hpp>

#include "enums.h"
#include "../math/vector2d.h"


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

        virtual void reset();
        virtual void copy(WorldObject_ptr object);

        void setLoc(float distance, float bearing);
        void setCameraId(CameraId cameraId)             { mCameraId = cameraId; }
        void setSeen(bool seen)                         { mSeen = seen; }
        void setTimestamp(qi::os::timeval timestamp)    { mTimestamp = timestamp; }

        Vector2D getLoc()               { return mLoc; }
        int getCameraId()               { return mCameraId; }
        bool isSeen()                   { return mSeen; }
        qi::os::timeval getTimeStamp()  { return mTimestamp; }

    protected:
        bool mCameraId;

    private:
        Vector2D mLoc;

        bool mSeen;

        qi::os::timeval mTimestamp;
    };
}

#endif // WORLDOBJECT_H
