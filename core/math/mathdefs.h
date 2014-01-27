#ifndef MATHDEFS_H
#define MATHDEFS_H

#include <cmath>

/**** Macros ********************************************************************/
#define kEpsilon    1.0e-6f

#define kPI         3.1415926535897932384626433832795f
#define kHalfPI     1.5707963267948966192313216916398f
#define kTwoPI      2.0f*kPI

#define kDegToRad   180.0/kPI

class MathDefs
{
    public:
        static bool    IsZero(float a)               { return (fabsf(a) < kEpsilon); }
        static bool    IsEqual(float a, float b)     { return (IsZero(a-b)); }
};

#endif // MATHDEFS_H
