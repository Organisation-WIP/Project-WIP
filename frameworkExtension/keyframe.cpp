#include "keyframe.h"


Keyframe::Keyframe(clock_t timestamp, float value)
    :value(value)
{
    this->timestamp = (timestamp<0 ? 0 : timestamp);
    InterpolationMethod* interp = Interpolation::getLinearInterpolation();
    leftInterp = interp;
    rightInterp = interp;
}
Keyframe::~Keyframe()
{}

void Keyframe::setInterpolation(InterpolationMethod* interp)
{
    if(interp == 0)
        interp = Interpolation::getLinearInterpolation();
    leftInterp = interp;
    rightInterp = interp;
}
void Keyframe::setInterpolationLeft(InterpolationMethod* interp)
{
    if(interp == 0)
        interp = Interpolation::getLinearInterpolation();
    leftInterp = interp;
}
void Keyframe::setInterpolationRight(InterpolationMethod* interp)
{
    if(interp == 0)
        interp = Interpolation::getLinearInterpolation();
    rightInterp = interp;
}

clock_t Keyframe::getTime()
{
    return timestamp;
}
float Keyframe::getValue()
{
    return value;
}
