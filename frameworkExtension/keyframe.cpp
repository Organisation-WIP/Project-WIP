#include "keyframe.h"


Keyframe::Keyframe(c_time time, float value)
    :time(time), value(value), next(0)
{}
Keyframe::~Keyframe()
{
    if(next)
        delete next;
}

void Keyframe::setNext(Keyframe* kf)
{
    next = kf;
}
Keyframe* Keyframe::getNext()
{
    return next;
}

clock_t Kyframe::getTime()
{
    return time;
}
float Keyframe::getValue(clock_t currTime)
{
    if(currTime <= time)
        return value;

    if(next)
    {
        if(next->getTime() < time)
            return value + ((next->value - value)* (currTime - time)/(next->time - time));      //erster + differenz*fortschritt_bis_naechster
        else
            return next->getValue(currTime);
    }
    return value;
}

float Keyframe::isFinished(clock_t currTime)
{
    if(currTime <= time)
        return false;

    if(next)
        return next->isFinished(currTime);
    return true;
}
