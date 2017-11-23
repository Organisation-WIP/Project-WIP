#include "keyframe.h"


Keyframe::Keyframe(clock_t timestamp, float value)
    :timestamp(timestamp), value(value), next(0)
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
void Keyframe::appendKeyframe(Keyframe *kf)
{
    if(next)
        next->appendKeyframe(kf);
    else
        next = kf;
}
Keyframe* Keyframe::getNext()
{
    return next;
}

clock_t Keyframe::getTime()
{
    return timestamp;
}
float Keyframe::getValue(clock_t currTime)
{
    if(currTime <= timestamp)
        return value;
    if(next)
    {
        if(currTime < next->getTime())
            return value + ((next->value - value)* (currTime - timestamp)/(next->timestamp - timestamp));      //erster + differenz*fortschritt_bis_naechster
        else
            return next->getValue(currTime);
    }
    return value;
}

bool Keyframe::isFinished(clock_t currTime)
{
    if(currTime <= timestamp)
        return false;

    if(next)
        return next->isFinished(currTime);
    return true;
}
