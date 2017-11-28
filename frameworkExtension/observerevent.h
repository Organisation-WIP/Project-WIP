#ifndef OBSERVEREVENT_H
#define OBSERVEREVENT_H

class Observer;

class ObserverEvent
{
public:
    ObserverEvent(Observer* source);

    Observer* getSource();

private:
    Observer* source;
};

#endif // OBSERVEREVENT_H
