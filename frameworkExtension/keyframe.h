#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>
#include "interpolation.h"


class Keyframe
{
    friend float Interpolation::interpolate(Keyframe *k1, Keyframe *k2, float progress);
public:
    Keyframe(clock_t timestamp, float value, InterpolationMethod* interp=0);
    ~Keyframe();

    void setInterpolation(InterpolationMethod* interp);
    void setInterpolationLeft(InterpolationMethod* interp);
    void setInterpolationRight(InterpolationMethod* interp);

    clock_t getTime();
    float getValue();

private:
    clock_t timestamp;
    float value;
    InterpolationMethod* leftInterp;
    InterpolationMethod* rightInterp;
};

#endif // KEYFRAME_H
