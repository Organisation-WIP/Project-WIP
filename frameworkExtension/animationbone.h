#ifndef ANIMATIONBONE_H
#define ANIMATIONBONE_H

#include <qstring.h>
#include <qmap.h>
#include "animationbonekeyframe.h"


class AnimationBone
{
public:
    AnimationBone(QString boneID);
    void insertKeyframe(c_time time, AnimationBoneKeyframe* keyframe);
    bool deleteKeyframe(c_time time);
    bool hasKeyframe(c_time time);
    int getKeyframeCount();

private:
    QString boneID;
    QMap<c_time, AnimationBoneKeyframe*> keyframes;
};

#endif // ANIMATIONBONE_H
