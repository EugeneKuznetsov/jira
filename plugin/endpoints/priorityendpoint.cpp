#include "priorityendpoint.h"

PriorityEndpoint::PriorityEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : PriorityEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
