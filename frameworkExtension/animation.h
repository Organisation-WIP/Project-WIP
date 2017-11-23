#ifndef ANIMATION_H
#define ANIMATION_H

#include <time.h>
#include <qlist.h>
#include "idleobserver.h"
#include "transformation.h"
#include "animationbone.h"
#include "model.h"


class Animation : public IdleObserver
{
public:
    class AnimatedModel
    {
    public:
        AnimatedModel(Model* model, bool replay=false, bool reverse=false);
        void setFinished();
        bool isFinished();
        bool isReplay();
        clock_t getStartTime();
        Model* getModel();

    private:
        bool finished, replay, reverse;
        clock_t startTime;
        Model* m;
    };

    Animation();
    void start(Model* model, bool replay=false, bool reverse=false);

    virtual void doIt() override;

private:
    clock_t duration,startTime;
    QList<AnimationBone*> animatedBones;
    QList<AnimatedModel*> animatedModels;
};

#endif // ANIMATION_H
