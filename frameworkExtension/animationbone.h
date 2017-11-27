#ifndef ANIMATIONBONE_H
#define ANIMATIONBONE_H

#include <qstring.h>
#include <qmap.h>
#include <time.h>
#include "animation.h"
#include "graph.h"


class AnimationBone
{
public:
    static const int TRANS_X,TRANS_Y,TRANS_Z,ROT_S,ROT_X,ROT_Y,ROT_Z,SCAL_X,SCAL_Y,SCAL_Z;

    AnimationBone(QString boneID);
    ~AnimationBone();
    QString getBoneID();
    void setGraph(int transformationType, Graph* graph);
    bool deleteGraph(int transformationType);
    bool hasGraph(int transformationType);
    clock_t getDuration();

    bool applyAnimation(Animation::AnimatedModel* aModel, clock_t duration);

private:
    QString boneID;
    Graph* transformationGraphs[10];
    clock_t* duration;
};

#endif // ANIMATIONBONE_H
