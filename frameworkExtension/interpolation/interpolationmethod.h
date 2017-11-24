#ifndef INTERPOLATIONMETHOD_H
#define INTERPOLATIONMETHOD_H


class InterpolationMethod
{
public:
    virtual float getValue(float val1, float val2, float progress) = 0;
};

#endif // INTERPOLATIONMETHOD_H
