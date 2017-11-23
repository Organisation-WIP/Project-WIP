#include "animation.h"
#include "animationbone.h"

Animation::Animation()
{}

bool Animation::addAnimationBone(AnimationBone *bone)
{
    QString boneID = bone->getBoneID();
    for(QList<AnimationBone*>::Iterator i = animatedBones.begin(); i<animatedBones.end(); i++)
        if((*i)->getBoneID() == boneID)
            return false;
    animatedBones.append(bone);
    return true;
}
bool Animation::removeAnimationBone(QString boneID)
{
    for(QList<AnimationBone*>::Iterator i = animatedBones.begin(); i<animatedBones.end(); i++)
        if((*i)->getBoneID() == boneID)
        {
            animatedBones.erase(i);
            return true;
        }
    return false;
}
void Animation::start(Model* model, bool replay, bool reverse)
{
    AnimatedModel* aModel = new AnimatedModel(model, replay, reverse);
    animatedModels.append(aModel);
}

void Animation::doIt()
{
    for(QList<Animation::AnimatedModel*>::Iterator i = animatedModels.begin(); i<animatedModels.end(); i++)
    {
        for(QList<AnimationBone*>::Iterator k = animatedBones.begin(); k<animatedBones.end(); k++)
        {
            (*k)->applyAnimation(*i);
        }
        if((*i)->isFinished())
        {
            if((*i)->isReplay())
                (*i)->reset();
            else
                animatedModels.erase(i);
        }
    }
}




Animation::AnimatedModel::AnimatedModel(Model* model, bool replay, bool reverse)
    :m(model), finished(false), replay(replay), reverse(reverse)
{
    startTime = std::clock();
}

void Animation::AnimatedModel::reset()
{
    finished = false;
    startTime = std::clock();
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
clock_t Animation::AnimatedModel::getStartTime()
{
    return startTime;
}

Model* Animation::AnimatedModel::getModel()
{
    return m;
}
