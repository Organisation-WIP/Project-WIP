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

    float getDuration();
    void insertKeyframe(Keyframe* keyframe);
    bool deleteKeyframe(float timestamp);
    QMap<float, Keyframe*> getKeyframes();

    float getValue(float currTime);
    bool isFinished(float currTime);

private:
    QMap<float, Keyframe*> keyframes;
    float duration;

    void updateDuration();
};

#endif // GRAPH_H
