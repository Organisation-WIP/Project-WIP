#ifndef ANIMATION_H
#define ANIMATION_H

#include <time.h>
#include <qlist.h>
#include "idleobserver.h"
#include "model.h"
#include "observee.h"

class AnimationBone;

class Animation : public IdleObserver, Observee
{
public:
    class AnimatedModel
    {
    public:
        AnimatedModel(Model* model, bool replay=false, bool reverse=false, Observer* listener=0);
        void reset();
        void setFinished();
        bool isFinished();
        bool isReplay();
        bool getReverseState();
        float getStartTime();
        Model* getModel();
        Observer* getObserver();

    private:
        bool finished, replay, reverse, reverseState;
        float startTime;
        Model* model;
        Observer* listener;
    };

    Animation();
    bool addAnimationBone(AnimationBone* bone);
    bool removeAnimationBone(QString boneID);
    void start(Model* model, bool replay=false, bool reverse=false, Observer* listener=0);
    void stop(Model* model);
    float getDuration();

    virtual void doIt() override;

private:
    QList<AnimationBone*> animatedBones;
    QList<AnimatedModel*> animatedModels;
    float duration;

    void updateDuration();
};

#endif // ANIMATION_H
