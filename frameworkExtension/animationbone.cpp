#include "animationbone.h"
#include <QQuaternion>

AnimationBone::AnimationBone(QString boneID)
    :boneID(boneID)
{
    memset(transKeyframes, 0, 9*sizeof(int));
}

void AnimationBone::insertKeyframe(int transformation, Keyframe* keyframe)
{
    if(transKeyframes[transformation])
        delete transKeyframes[transformation];

    transKeyframes[transformation = keyframe;]
}
bool AnimationBone::deleteKeyframe(int transformation)
{
    if(transKeyframes[transformation])
    {
        delete transKeyframes[transformation];
        transKeyframes[transformation] = 0;
        return true;
    }
    return false;
}
bool AnimationBone::hasKeyframe(int transformation)
{
    return transKeyframes[transformation] != 0;
}

void AnimationBone::applyAnimation(Animation::AnimatedModel* aModel)
{
    clock_t currTime = std::clock() - aModel->getStartTime();
    Bone* bone = aModel->getModel()->getBone(boneID);

    float transformation[9];
    bool finished = true;
    for(int i=0;i<9;i++)
    {
        transformation[i] = transKeyframes[i]->getValue(currTime);
        finished = finished && transKeyframes[i]->isFinished(currTime);
    }

    bone->translate(transformation[0],transformation[1],transformation[2]);
    QQuaternion quat = QQuaternion::fromEulerAngles(transformation[3],transformation[4],transformation[5]);
    bone->rotate(quat.scalar(), quat.vector());
    bone->scale(transformation[6],transformation[7],transformation[8]);

    if(finished)
        aModel->setFinished();
}
