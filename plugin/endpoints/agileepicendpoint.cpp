#include "agileepicendpoint.h"

AgileEpicEndpoint::AgileEpicEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AgileEpicEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AgileEpicEndpoint::onMoveIssuesToEpicRequest()
{
    return AgileEpicEndpointProxy::onMoveIssuesToEpicRequest();
}

Reply *AgileEpicEndpoint::onPartiallyUpdateEpicRequest()
{
    return AgileEpicEndpointProxy::onPartiallyUpdateEpicRequest();
}

Reply *AgileEpicEndpoint::onRankEpicsRequest()
{
    return AgileEpicEndpointProxy::onRankEpicsRequest();
}

Reply *AgileEpicEndpoint::onRemoveIssuesFromEpicRequest()
{
    return AgileEpicEndpointProxy::onRemoveIssuesFromEpicRequest();
}
