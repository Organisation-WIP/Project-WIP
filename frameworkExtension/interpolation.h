#ifndef INTERPOLATION_H
#define INTERPOLATION_H

class Keyframe;

class Interpolation
{
public:
    Interpolation();

    static float interpolate(Keyframe* k1, Keyframe* k2, float progress);
};

#endif // INTERPOLATION_H
