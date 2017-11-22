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

void AnimationBone::prepareAnimationStart()
{
    finished = false;
    startTime = std::clock();
    keyframeStartTime = startTime;
    currentKeyframe = keyframes.begin();
    nextKeyframe = currentKeyframe + 1;
}
bool AnimationBone::isFinished()
{
    return finished;
}

void AnimationBone::applyAnimation(Bone *bone)
{
    clock_t currTime = std::clock();
    if(currTime-startTime >= nextKeyframe.key())
    {
        keyframeStartTime += currentKeyframe.key();
        currentKeyframe = nextKeyframe;
        nextKeyframe++;
        if(nextKeyframe == keyframes.end())
        {
            finished = true;
        }
    }

    int trans[3] = {currentKeyframe.value()->get}
    bone->translate();
}
