#ifndef ANIMATION_H
#define ANIMATION_H

#include <time.h>
#include <qlist.h>
#include "idleobserver.h"
#include "transformation.h"
#include "model.h"

class AnimationBone;

class Animation : public IdleObserver
{
public:
    class AnimatedModel
    {
    public:
        AnimatedModel(Model* model, bool replay=false, bool reverse=false);
        void reset();
        void setFinished();
        bool isFinished();
        bool isReplay();
        bool getReverseState();
        clock_t getStartTime();
        Model* getModel();

    private:
        bool finished, replay, reverse, reverseState;
        clock_t startTime;
        Model* m;
    };

    Animation();
    bool addAnimationBone(AnimationBone* bone);
    bool removeAnimationBone(QString boneID);
    void start(Model* model, bool replay=false, bool reverse=false);

    virtual void doIt() override;

private:
    QList<AnimationBone*> animatedBones;
    QList<AnimatedModel*> animatedModels;
};

#endif // ANIMATION_H
