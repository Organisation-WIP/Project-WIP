#include "animationbone.h"
#include <QQuaternion>

AnimationBone::AnimationBone(QString boneID)
    :boneID(boneID), duration(0)
{
    for(int i=0;i<10;i++)
        transKeyframes[i] = 0;
}
AnimationBone::~AnimationBone()
{
    for(int i=0;i<10;i++)
        if(transKeyframes[i])
            delete transKeyframes[i];
}

QString AnimationBone::getBoneID()
{
    return boneID;
}
void AnimationBone::setKeyframe(int transformationType, Keyframe* keyframe)
{
    if(transKeyframes[transformationType])
        delete transKeyframes[transformationType];

    transKeyframes[transformationType] = keyframe;
    updateDuration();
}
bool AnimationBone::deleteKeyframe(int transformationType)
{
    if(transKeyframes[transformationType])
    {
        delete transKeyframes[transformationType];
        transKeyframes[transformationType] = 0;
        updateDuration();
        return true;
    }
    return false;
}
bool AnimationBone::hasKeyframe(int transformationType)
{
    return transKeyframes[transformationType] != 0;
}
clock_t AnimationBone::getDuration()
{
    return duration;
}

void AnimationBone::applyAnimation(Animation::AnimatedModel* aModel)
{
    bool reverseState = aModel->getReverseState();
    clock_t currTime = std::clock() - aModel->getStartTime();
    if(reverseState)
        currTime = duration-currTime;

    Bone* bone = aModel->getModel()->getBone(boneID);
    if(!bone)
    {
        aModel->setFinished();
        return;
    }

    bool finished = true;
    float transformation[10];
    bone->getTranslation(transformation);
    bone->getRotation(transformation+3);
    bone->getScale(transformation+7);

    for(int i=0;i<10;i++)
    {
        if(transKeyframes[i])
        {
            transformation[i] = transKeyframes[i]->getValue(currTime);
            if(!reverseState)
                finished = finished && transKeyframes[i]->isFinished(currTime);
        }
    }
    if(reverseState)
        finished = currTime <= 0;

    bone->resetTrafo();
    bone->translate(transformation[0],transformation[1],transformation[2]);
    bone->rotate(transformation[3],transformation[4],transformation[5],transformation[6]);
    bone->scale(transformation[7],transformation[8],transformation[9]);

    if(finished)
        aModel->setFinished();
}


void AnimationBone::updateDuration()
{
    duration = 0;
    for(int i=0;i<10;i++)
    {
        if(transKeyframes[i])
        {
            clock_t tempDuration = transKeyframes[i]->getDuration();
            if(tempDuration > duration)
                duration = tempDuration;
        }
    }
}
