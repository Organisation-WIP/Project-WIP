#ifndef OBSERVEREVENT_H
#define OBSERVEREVENT_H

class Observee;

class ObserverEvent
{
public:
    ObserverEvent(Observee* source);

    Observee* getSource();

private:
    Observee* source;
};

#endif // OBSERVEREVENT_H
