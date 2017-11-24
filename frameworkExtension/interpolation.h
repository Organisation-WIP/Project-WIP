#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "interpolation/linearinterpolation.h"

class Keyframe;

class Interpolation
{
public:
    Interpolation();

    static InterpolationMethod* getLinearInterpolation();

    static float interpolate(Keyframe* k1, Keyframe* k2, float progress);

private:
    static LinearInterpolation linear;
};

#endif // INTERPOLATION_H
