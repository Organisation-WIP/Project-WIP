#include "animationbone.h"

AnimationBone::AnimationBone(QString boneID)
    :boneID(boneID)
{}

void AnimationBone::insertKeyframe(c_time time, AnimationBoneKeyframe* keyframe)
{
    keyframes.insert(time, keyframe);
}
bool AnimationBone::deleteKeyframe(c_time time)
{
    return keyframes.remove(time) > 0;
}
bool AnimationBone::hasKeyframe(c_time time)
{
    return keyframes.value(time, 0) != 0;
}
int AnimationBone::getKeyframeCount()
{
    return keyframes.count();
}
