#include "animationbone.h"
#include <QQuaternion>

const int AnimationBone::TRANS_X = 0;
const int AnimationBone::TRANS_Y = 1;
const int AnimationBone::TRANS_Z = 2;
const int AnimationBone::ROT_S = 3;
const int AnimationBone::ROT_X = 4;
const int AnimationBone::ROT_Y = 5;
const int AnimationBone::ROT_Z = 6;
const int AnimationBone::SCAL_X = 7;
const int AnimationBone::SCAL_Y = 8;
const int AnimationBone::SCAL_Z = 9;

AnimationBone::AnimationBone(QString boneID)
    :boneID(boneID)
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
}
bool AnimationBone::deleteGraph(int transformationType)
{
    if(transformationGraphs[transformationType])
    {
        delete transformationGraphs[transformationType];
        transformationGraphs[transformationType] = 0;
        return true;
    }
    return false;
}
bool AnimationBone::hasGraph(int transformationType)
{
    return transformationGraphs[transformationType] != 0;
}
float AnimationBone::getDuration()
{
    float dur = 0;
    for(int i=0;i<10;i++)
    {
        if(transformationGraphs[i])
        {
            float tempDur = transformationGraphs[i]->getDuration();
            if(tempDur > dur)
                dur = tempDur;
        }
    }
    return dur;
}

bool AnimationBone::applyAnimation(Animation::AnimatedModel* aModel, float duration)
{
    bool reverseState = aModel->getReverseState();
    float currTime = (clock()/(float)CLOCKS_PER_SEC) - aModel->getStartTime();
    if(reverseState)
        currTime = duration-currTime;

    Bone* bone = aModel->getModel()->getBone(boneID);
    if(!bone)
    {
        aModel->setFinished();
        return true;
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

    return finished;
}
