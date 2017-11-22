#ifndef ANIMATION_H
#define ANIMATION_H

#include <time.h>
#include <qlist.h>
#include "idleobserver.h"
#include "transformation.h"
#include "animationbone.h"


class Animation : public IdleObserver
{
public:
    Animation();

    virtual void doIt() override;

private:
    clock_t duration,startTime;
    QList<AnimationBone*> animatedBones;
};

#endif // ANIMATION_H
