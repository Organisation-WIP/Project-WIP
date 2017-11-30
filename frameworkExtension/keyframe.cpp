#include "keyframe.h"


Keyframe::Keyframe(float time, float value)
    :value(value), leftInterp(0.9,0.9), rightInterp(0.1,0.1)
{
    this->time = (time<0 ? 0 : time);
}
Keyframe::~Keyframe()
{}

void Keyframe::setInterpolation(QVector2D pointLeft, QVector2D pointRight)
{
    if(pointRight.x() <= 0)
        pointRight.setX(0.01);
    if(pointLeft.x() >= 1)
        pointLeft.setX(0.99);
    if(pointRight.x() >= 0.5)
        pointRight.setX(0.49);
    if(pointLeft.x() <= 0.5)
        pointLeft.setX(0.51);

    leftInterp = pointLeft;
    rightInterp = pointRight;
}
void Keyframe::setInterpolationLeft(QVector2D point)
{
    if(point.x() >= 1)
        point.setX(0.99);
    if(point.x() <= 0.5)
        point.setX(0.51);

    leftInterp = point;
}
void Keyframe::setInterpolationRight(QVector2D point)
{
    if(point.x() <= 0)
        point.setX(0.01);
    if(point.x() >= 0.5)
        point.setX(0.49);

    rightInterp = point;
}

float Keyframe::getTime()
{
    return time;
}
float Keyframe::getValue()
{
    return value;
}
