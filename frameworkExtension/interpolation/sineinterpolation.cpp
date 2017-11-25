#include "sineinterpolation.h"
#include "math.h"

SineInterpolation::SineInterpolation()
{

}

float SineInterpolation::getValue(float val1, float val2, float progress)
{
    if(progress > 1)
        progress = 1;
    else if(progress < 0)
        progress = 0;
    return val1 + (val2-val1)*(cos(progress*M_PI)*(-0.5)+0.5);
}
