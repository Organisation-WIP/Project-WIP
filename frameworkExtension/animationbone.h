#ifndef ANIMATIONBONE_H
#define ANIMATIONBONE_H

#include <qstring.h>
#include <qmap.h>
#include <time.h>
#include "animation.h"
#include "keyframe.h"

#define BONE_TRANS_X 0
#define BONE_TRANS_Y 1
#define BONE_TRANS_Z 2
#define BONE_ROT_X 3
#define BONE_ROT_Y 4
#define BONE_ROT_Z 5
#define BONE_SCAL_X 6
#define BONE_SCAL_Y 7
#define BONE_SCAL_Z 8

class AnimationBone
{
public:
    AnimationBone(QString boneID);
    void insertKeyframe(int transformation, Keyframe* keyframe);
    bool deleteKeyframe(int transformation);
    bool hasKeyframe(int transformation);

    void applyAnimation(Animation::AnimatedModel* aModel);

private:
    QString boneID;
    Keyframe* transKeyframes[9];
};

#endif // ANIMATIONBONE_H
