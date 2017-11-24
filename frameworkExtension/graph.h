#ifndef GRAPH_H
#define GRAPH_H

#include <time.h>
#include <QMap>
#include "keyframe.h"


class Graph
{
public:
    Graph();
    ~Graph();

    clock_t getDuration();
    void insertKeyframe(Keyframe* keyframe);
    bool deleteKeyframe(clock_t timestamp);
    QMap<clock_t, Keyframe*> getKeyframes();

    float getValue(clock_t currTime);

private:
    QMap<clock_t, Keyframe*> keyframes;
    clock_t duration;

    void updateDuration();
};

#endif // GRAPH_H
