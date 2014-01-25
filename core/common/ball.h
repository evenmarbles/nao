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

    private:
    };
}

#endif // BALL_H
