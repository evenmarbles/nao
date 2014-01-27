#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>

struct Point2D
{
    double x;
    double y;
};

class Vector2D
{
public:
    double x;
    double y;

public:
    Vector2D(float px = 0, float py = 0);
    ~Vector2D() {}
};

#endif // VECTOR2D_H
