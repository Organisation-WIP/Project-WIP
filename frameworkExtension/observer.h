#ifndef OBSERVER_H
#define OBSERVER_H

#include "observerevent.h"

class Observer
{
public:
    virtual void actionPerformed(ObserverEvent* event) = 0;
};

#endif // OBSERVER_H
