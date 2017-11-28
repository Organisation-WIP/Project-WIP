#ifndef OBSERVEE_H
#define OBSERVEE_H

#include <QList>
#include "observer.h"
#include "observerevent.h"

class Observee
{
public:
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);

protected:
    void informObservers(ObserverEvent* event);

private:
    QList<Observer*> obsList;
};

#endif // OBSERVEE_H
