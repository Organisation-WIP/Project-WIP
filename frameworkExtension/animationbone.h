#ifndef ANIMATIONBONE_H
#define ANIMATIONBONE_H

#include <qstring.h>
#include <qmap.h>
#include <time.h>
#include "animation.h"
#include "graph.h"

#define BONE_TRANS_X 0
#define BONE_TRANS_Y 1
#define BONE_TRANS_Z 2
#define BONE_ROT_S 3
#define BONE_ROT_X 4
#define BONE_ROT_Y 5
#define BONE_ROT_Z 6
#define BONE_SCAL_X 7
#define BONE_SCAL_Y 8
#define BONE_SCAL_Z 9

class AnimationBone
{
public:
    AnimationBone(QString boneID);
    ~AnimationBone();
    QString getBoneID();
    void setGraph(int transformationType, Graph* graph);
    bool deleteGraph(int transformationType);
    bool hasGraph(int transformationType);
    clock_t getDuration();

    void applyAnimation(Animation::AnimatedModel* aModel);

private:
    QString boneID;
    Graph* transformationGraphs[10];
    clock_t duration;

    void updateDuration();
};

#endif // ANIMATIONBONE_H
