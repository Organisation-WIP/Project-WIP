#ifndef SINEINTERPOLATION_H
#define SINEINTERPOLATION_H

#include "interpolationmethod.h"

class Interpolation;

class SineInterpolation : public InterpolationMethod
{
    friend class Interpolation;

    SineInterpolation();

public:
    virtual float getValue(float val1, float val2, float progress);
};

#endif // SINEINTERPOLATION_H
