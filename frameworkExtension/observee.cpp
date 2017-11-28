#include "observee.h"

void Observee::addObserver(Observer* obs)
{
    QList<Observer*>::iterator end = obsList.end();
    for(QList<Observer*>::iterator i=obsList.begin(); i!=end; i++)
        if((*i) == obs)
            return;
    obsList.append(obs);
}
void Observee::removeObserver(Observer *obs)
{
    QList<Observer*>::iterator end = obsList.end();
    for(QList<Observer*>::iterator i=obsList.begin(); i!=end; i++)
    {
        if((*i) == obs)
        {
            obsList.erase(i);
            return;
        }
    }
}


void Observee::informObservers(ObserverEvent *event)
{
    QList<Observer*>::iterator end = obsList.end();
    for(QList<Observer*>::iterator i=obsList.begin(); i!=end; i++)
        (*i)->actionPerformed(event);
}
