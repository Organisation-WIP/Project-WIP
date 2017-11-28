#include "keyframe.h"


Keyframe::Keyframe(float time, float value, InterpolationMethod* interp)
    :value(value)
{
    this->time = (time<0 ? 0 : time);
    if(!interp)
        interp = Interpolation::getLinearInterpolation();
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

float Keyframe::getTime()
{
    return time;
}
float Keyframe::getValue()
{
    return value;
}
