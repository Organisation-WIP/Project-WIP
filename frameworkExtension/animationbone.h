#ifndef ANIMATIONBONE_H
#define ANIMATIONBONE_H

#include <qstring.h>
#include <qmap.h>
#include <time.h>
#include "animationbonekeyframe.h"


class AnimationBone
{
public:
    AnimationBone(QString boneID);
    void insertKeyframe(c_time time, AnimationBoneKeyframe* keyframe);
    bool deleteKeyframe(c_time time);
    bool hasKeyframe(c_time time);
    int getKeyframeCount();

    void prepareAnimationStart();
    bool isFinished();

    void applyAnimation(Bone* bone);

private:
    QString boneID;
    bool finished;
    clock_t startTime,keyframeStartTime;
    QMap<clock_t, AnimationBoneKeyframe*> keyframes;
    QMap::Iterator currentKeyframe, nextKeyframe;
};

#endif // ANIMATIONBONE_H
