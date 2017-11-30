#include "interpolation.h"
#include "keyframe.h"
#include <vector>

Interpolation::Interpolation()
{}

float Interpolation::interpolate(Keyframe *k1, Keyframe *k2, float progress)
{
    if(progress > 1)
        progress = 1;
    else if(progress < 0)
        progress = 0;

    std::vector<double> x(4),y(4);
    float val1 = k1->getValue();
    float val2 = k2->getValue();
    float dif = val2 - val1;
    x[0] = 0;
    y[0] = val1;
    x[3] = 1;
    y[3] = val2;

    x[1] = k1->rightInterp.x();
    y[1] = val1 + dif*k1->rightInterp.y();
    x[2] = k2->leftInterp.x();
    y[2] = val1 + dif*k2->leftInterp.y();

    tk::spline s;
    s.set_points(x,y);

    return s(progress);
}
