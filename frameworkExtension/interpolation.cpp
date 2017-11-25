#include "interpolation.h"
#include "keyframe.h"

LinearInterpolation Interpolation::linear;
SineInterpolation Interpolation::sine;

Interpolation::Interpolation()
{}

InterpolationMethod* Interpolation::getLinearInterpolation()
{
    return &Interpolation::linear;
}
InterpolationMethod* Interpolation::getSineInterpolation()
{
    return &Interpolation::sine;
}

float Interpolation::interpolate(Keyframe *k1, Keyframe *k2, float progress)
{
    if(progress > 1)
        progress = 1;
    else if(progress < 0)
        progress = 0;

    float val1 = k1->getValue();
    float val2 = k2->getValue();
    InterpolationMethod* interp;
    if(progress < 0.5)
        interp = k1->rightInterp;
    else
        interp = k2->leftInterp;
    return interp->getValue(val1, val2, progress);
}
