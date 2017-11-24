#include "linearinterpolation.h"

LinearInterpolation::LinearInterpolation()
{}

float LinearInterpolation::getValue(float val1, float val2, float progress)
{
    if(progress > 1)
        progress = 1;
    else if(progress < 0)
        progress = 0;
    return val1 + ((val2-val1) * progress);
}
