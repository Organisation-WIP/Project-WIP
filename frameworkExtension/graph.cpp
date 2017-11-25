#include "graph.h"

Graph::Graph()
    :duration(0)
{}
Graph::~Graph()
{
    QMap<clock_t, Keyframe*>::iterator end = keyframes.end();
    for(QMap<clock_t, Keyframe*>::iterator i=keyframes.begin(); i!=end; i++)
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
    QMap<clock_t, Keyframe*>::iterator end = keyframes.end();
    for(QMap<clock_t, Keyframe*>::iterator i=keyframes.begin(); i!=end; i++)
    {
        clock_t time1 = i.key();
        if(currTime <= time1)
            return i.value()->getValue();

        QMap<clock_t, Keyframe*>::iterator next = i+1;
        if(next != end)
        {
            clock_t time2 = next.key();
            if(currTime < time2)
                return Interpolation::interpolate(i.value(), next.value(), ((float)currTime-time1)/(time2-time1));
            continue;
        }
        return i.value()->getValue();
    }
}
bool Graph::isFinished(clock_t currTime)
{
    return currTime >= duration;
}


void Graph::updateDuration()
{
    if(keyframes.size())
        duration = (--keyframes.end()).key();
    else
        duration = 0;
}
