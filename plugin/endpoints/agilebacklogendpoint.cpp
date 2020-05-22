#include "agilebacklogendpoint.h"

AgileBacklogEndpoint::AgileBacklogEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AgileBacklogEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AgileBacklogEndpoint::onMoveIssuesToBacklogRequest()
{
    return AgileBacklogEndpointProxy::onMoveIssuesToBacklogRequest();
}
