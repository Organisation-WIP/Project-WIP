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
    void setKeyframe(int transformationType, Keyframe* keyframe);
    bool deleteKeyframe(int transformationType);
    bool hasKeyframe(int transformationType);

    void applyAnimation(Animation::AnimatedModel* aModel);

private:
    QString boneID;
    Keyframe* transKeyframes[10];
};

#endif // ANIMATIONBONE_H
