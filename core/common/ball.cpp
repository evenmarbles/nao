#include "ball.h"
#include "imageconstants.h"

#include <cmath>

using namespace IAL;

const float Ball::RADIUS = 60.0f;

Ball::Ball():
    WorldObject()
{
}

void Ball::copy(Ball_ptr object)
{
    mDistance = object->getDistance();
    mImageRadius = object->getImageRadius();
    mImageCenter = object->getImageCenter();

    WorldObject::copy(object);
}

void Ball::setDistance(float pitch)
{
    mDistance = 16765.0f * pow(mImageRadius * 2.0f, -0.83f); //-0.769f
    mDistance = cos(pitch) * mDistance;
}
