#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "interpolation/linearinterpolation.h"
#include "interpolation/sineinterpolation.h"

class Keyframe;

class Interpolation
{
public:
    Interpolation();

    static InterpolationMethod* getLinearInterpolation();
    static InterpolationMethod* getSineInterpolation();

    static float interpolate(Keyframe* k1, Keyframe* k2, float progress);

private:
    static LinearInterpolation linear;
    static SineInterpolation sine;
};

#endif // INTERPOLATION_H
