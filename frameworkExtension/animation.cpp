#include "animation.h"
#include "animationbone.h"

Animation::Animation()
{}

bool Animation::addAnimationBone(AnimationBone *bone)
{
    QString boneID = bone->getBoneID();
    QList<AnimationBone*>::iterator end = animatedBones.end();
    for(QList<AnimationBone*>::iterator i = animatedBones.begin(); i!=end; i++)
        if((*i)->getBoneID() == boneID)
            return false;
    animatedBones.append(bone);
    updateDuration();
    return true;
}
bool Animation::removeAnimationBone(QString boneID)
{
    QList<AnimationBone*>::iterator end = animatedBones.end();
    for(QList<AnimationBone*>::iterator i = animatedBones.begin(); i!=end; i++)
        if((*i)->getBoneID() == boneID)
        {
            animatedBones.erase(i);
            updateDuration();
            return true;
        }
    updateDuration();
    return false;
}
void Animation::start(Model* model, bool replay, bool reverse, Observer* listener)
{
    QList<Animation::AnimatedModel*>::iterator end = animatedModels.end();
    for(QList<Animation::AnimatedModel*>::iterator i = animatedModels.begin(); i!=end; i++)
    {
        if((*i)->getModel() == model)
        {
            animatedModels.erase(i);
        }
    }
    AnimatedModel* aModel = new AnimatedModel(model, replay, reverse, listener);
    animatedModels.append(aModel);
}
void Animation::stop(Model *model)
{
    QList<Animation::AnimatedModel*>::iterator end = animatedModels.end();
    for(QList<Animation::AnimatedModel*>::iterator i = animatedModels.begin(); i!=end; i++)
    {
        if((*i)->getModel() == model)
        {
            animatedModels.erase(i);
            return;
        }
    }
}

void Animation::doIt()
{
    QList<Animation::AnimatedModel*>::iterator end = animatedModels.end();
    for(QList<Animation::AnimatedModel*>::iterator i = animatedModels.begin(); i!=end; i++)
    {
        bool finished = true;
        for(QList<AnimationBone*>::iterator k = animatedBones.begin(); k<animatedBones.end(); k++)
        {
            bool boneFinished = (*k)->applyAnimation(*i, duration);
            finished = finished && boneFinished;
        }
        if(finished)
        {
            if((*i)->isReplay())
                (*i)->reset();
            else
            {
                Observer* listener = (*i)->getObserver();
                if(listener)
                    listener->actionPerformed(new ObserverEvent(this));
                animatedModels.erase(i);
            }
        }
    }
}


void Animation::updateDuration()
{
    duration = 0;
    QList<AnimationBone*>::iterator end = animatedBones.end();
    for(QList<AnimationBone*>::iterator i=animatedBones.begin(); i!=end; i++)
    {
        int tempDur = (*i)->getDuration();
        if(tempDur > duration)
            duration = tempDur;
    }
}




Animation::AnimatedModel::AnimatedModel(Model* model, bool replay, bool reverse, Observer* listener)
    :model(model), finished(false), replay(replay), reverse(reverse), reverseState(false), listener(listener)
{
    startTime = clock()/(float)CLOCKS_PER_SEC;
}

void Animation::AnimatedModel::reset()
{
    finished = false;
    startTime = clock()/(float)CLOCKS_PER_SEC;
    if(reverse)
        reverseState = !reverseState;
}
bool Animation::AnimatedModel::isFinished()
{
    return finished;
}
void Animation::AnimatedModel::setFinished()
{
    finished = true;
}

bool Animation::AnimatedModel::isReplay()
{
    return replay;
}
bool Animation::AnimatedModel::getReverseState()
{
    return reverseState;
}
float Animation::AnimatedModel::getStartTime()
{
    return startTime;
}

Model* Animation::AnimatedModel::getModel()
{
    return model;
}
Observer* Animation::AnimatedModel::getObserver()
{
    return listener;
}
