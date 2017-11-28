#include "observerevent.h"
#include "observer.h"

ObserverEvent::ObserverEvent(Observer* source)
    :source(source)
{}

Observer* ObserverEvent::getSource()
{
    return source;
}
