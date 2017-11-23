#include "animation.h"

Animation::Animation()
    :replay(false), replayReverse(false)
{

}
void Animation::setReplay(bool replay, bool reverse)
{
    this->replay = replay;
    replayReverse = reverse;
}

void Animation::start(Model* model, bool replay=false, bool reverse=false)
{
    AnimatedModel* aModel = new AnimatedMode(model, replay, reverse);
    animatedModels.append(aModel);
}

void Animation::doIt()
{
    for(QList::Iterator i = animatedModels.begin(); i<animatedModels.end(); i++)
    {
        for(QList::Iterator k = animatedBones.begin(); k<animatedBones.end(); k++)
            (*k)->applyAnimation(*i);
        if((*i)->isFinished())
            animatedModels.erase(i);
    }
}




Animation::AnimatedModel::AnimatedModel(Model* model, bool replay, bool reverse)
    :m(model), finished(false), replay(replay), reverse(reverse)
{
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
