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
    Animation();
    void setReplay(bool replay, bool reverse=false);
    void start(Model* model);

    virtual void doIt() override;

private:
    bool replay,replayReverse;
    clock_t duration,startTime;
    QList<AnimationBone*> animatedBones;
};

#endif // ANIMATION_H
