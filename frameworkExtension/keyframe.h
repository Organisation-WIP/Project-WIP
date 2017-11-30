#ifndef KEYFRAME_H
#define KEYFRAME_H

#include <qlist.h>
#include <time.h>
#include <QVector2D>
#include "interpolation.h"
#include "spline.h"


class Keyframe
{
    friend float Interpolation::interpolate(Keyframe *k1, Keyframe *k2, float progress);
public:
    Keyframe(float time, float value);
    ~Keyframe();

    void setInterpolation(QVector2D pointLeft, QVector2D pointRight);
    void setInterpolationLeft(QVector2D point);
    void setInterpolationRight(QVector2D point);

    float getTime();
    float getValue();

private:
    float time;
    float value;
    QVector2D leftInterp;
    QVector2D rightInterp;
};

#endif // KEYFRAME_H
