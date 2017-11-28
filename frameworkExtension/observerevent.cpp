#include "observerevent.h"
#include "observer.h"

ObserverEvent::ObserverEvent(Observee* source)
    :source(source)
{}

Observee* ObserverEvent::getSource()
{
    return source;
}
