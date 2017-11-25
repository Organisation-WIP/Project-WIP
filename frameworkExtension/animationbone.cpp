#include "animationbone.h"
#include <QQuaternion>
AnimationBone::AnimationBone(QString boneID)
    :boneID(boneID), duration(0)
{
    for(int i=0;i<10;i++)
        transformationGraphs[i] = 0;
}
AnimationBone::~AnimationBone()
{
    for(int i=0;i<10;i++)
        if(transformationGraphs[i])
            delete transformationGraphs[i];
}

QString AnimationBone::getBoneID()
{
    return boneID;
}
void AnimationBone::setGraph(int transformationType, Graph* graph)
{
    if(transformationGraphs[transformationType])
        delete transformationGraphs[transformationType];

    transformationGraphs[transformationType] = graph;
    updateDuration();
}
bool AnimationBone::deleteGraph(int transformationType)
{
    if(transformationGraphs[transformationType])
    {
        delete transformationGraphs[transformationType];
        transformationGraphs[transformationType] = 0;
        updateDuration();
        return true;
    }
    return false;
}
bool AnimationBone::hasGraph(int transformationType)
{
    return transformationGraphs[transformationType] != 0;
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
        if(transformationGraphs[i])
        {
            transformation[i] = transformationGraphs[i]->getValue(currTime);
            if(!reverseState)
                finished = finished && transformationGraphs[i]->isFinished(currTime);
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
        if(transformationGraphs[i])
        {
            clock_t tempDuration = transformationGraphs[i]->getDuration();
            if(tempDuration > duration)
                duration = tempDuration;
        }
    }
}
