#ifndef BALL_H
#define BALL_H

#include "worldobject.h"


namespace IAL
{
    class Ball;
    typedef boost::shared_ptr<Ball> Ball_ptr;


    class Ball : public WorldObject
    {
    public:
        Ball();
        virtual ~Ball() {}

        WorldObjectType getType()   { return WORLD_OBJECT_BALL; }

        void copy(Ball_ptr object);

        void setDistance(float pitch);
        void setImageRadius(int radius)         { mImageRadius = static_cast<float>(radius); }
        void setImageCenter(float x, float y)   { mImageCenter.x = x; mImageCenter.y = y; }

        float getDistance()             { return mDistance; }

    private:
        float getImageRadius()          { return mImageRadius; }
        Point2D getImageCenter()        { return mImageCenter; }

        float mDistance;
        float mElevation;
        float mImageRadius;
        Point2D mImageCenter;

        static const float RADIUS;
    };
}

#endif // BALL_H
