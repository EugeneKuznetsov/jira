#include "priorityschemesendpoint.h"

PrioritySchemesEndpoint::PrioritySchemesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : PrioritySchemesEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *PrioritySchemesEndpoint::onCreatePrioritySchemeRequest()
{
    return PrioritySchemesEndpointProxy::onCreatePrioritySchemeRequest();
}

Reply *PrioritySchemesEndpoint::onUpdatePrioritySchemeRequest()
{
    return PrioritySchemesEndpointProxy::onUpdatePrioritySchemeRequest();
}
