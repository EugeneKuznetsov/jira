#include "componentendpoint.h"

ComponentEndpoint::ComponentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ComponentEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ComponentEndpoint::onCreateComponentRequest()
{
    return ComponentEndpointProxy::onCreateComponentRequest();
}

Reply *ComponentEndpoint::onUpdateComponentRequest()
{
    return ComponentEndpointProxy::onUpdateComponentRequest();
}
