#include "interpolation.h"
#include "keyframe.h"

Interpolation::Interpolation()
{}

InterpolationMethod* Interpolation::getLinearInterpolation()
{
    return &linear;
}

float Interpolation::interpolate(Keyframe *k1, Keyframe *k2, float progress)
{
    if(progress > 1)
        progress = 1;
    else if(progress < 0)
        progress = 0;

    float val1 = k1->getValue();
    float val2 = k2->getValue();
    if(progress < 0.5)
        return k1->rightInterp->getValue(val1, val1 + (val2-val1)/2, progress*2);
    return k2->leftInterp->getValue(val1 + (val2-val1)/2, val2, (progress-0.5)*2);
}
