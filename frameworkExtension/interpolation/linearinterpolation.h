#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_H

#include "interpolationmethod.h"

class Interpolation;

class LinearInterpolation : public InterpolationMethod
{
    friend class Interpolation;

    LinearInterpolation();

public:
    virtual float getValue(float val1, float val2, float progress);
};

#endif // LINEARINTERPOLATION_H
