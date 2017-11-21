#ifndef ANIMATION_H
#define ANIMATION_H

#include <time.h>
#include "idleobserver.h"
#include "transformation.h"


class Animation : public IdleObserver
{
public:
    Animation();

    virtual void doIt() override;

private:
    clock_t duration,startTime;
};

#endif // ANIMATION_H
