#include "graph.h"

Graph::Graph()
    :duration(0)
{}
Graph::~Graph()
{
    for(QMap<clock_t, Keyframe*>::iterator i=keyframes.begin(); i<keyframes.end(); i++)
        delete i.value();
}


clock_t Graph::getDuration()
{
    return duration;
}
void Graph::insertKeyframe(Keyframe* keyframe)
{
    Keyframe* oldValue = keyframes.value(keyframe->getTime(), 0);
    if(oldValue)
        delete oldValue;
    keyframes.insert(keyframe->getTime(), keyframe);
    updateDuration();
}
bool Graph::deleteKeyframe(clock_t timestamp)
{
    bool success = keyframes.remove(timestamp) > 0;
    updateDuration();
    return success;
}
QMap<clock_t, Keyframe*> Graph::getKeyframes()
{
    return keyframes;
}

float Graph::getValue(clock_t currTime)
{
    for(QMap<clock_t, Keyframe*>::iterator i=keyframes.begin(); i<keyframes.end(); i++)
    {

    }
    /*if(currTime <= timestamp)
        return value;
    if(next)
    {
        if(currTime < next->getTime())
            return value + ((next->value - value)* (currTime - timestamp)/(next->timestamp - timestamp));      //erster + differenz*fortschritt_bis_naechster
        else
            return next->getValue(currTime);
    }
    return value;*/
}


void Graph::updateDuration()
{
    if(keyframes.size())
        duration = (--keyframes.end()).key();
    else
        duration = 0;
}
