#include "agilesprintendpoint.h"

AgileSprintEndpoint::AgileSprintEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AgileSprintEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AgileSprintEndpoint::onCreateSprintRequest()
{
    return AgileSprintEndpointProxy::onCreateSprintRequest();
}

Reply *AgileSprintEndpoint::onMoveIssuesToSprintRequest()
{
    return AgileSprintEndpointProxy::onMoveIssuesToSprintRequest();
}

Reply *AgileSprintEndpoint::onPartiallyUpdateSprintRequest()
{
    return AgileSprintEndpointProxy::onPartiallyUpdateSprintRequest();
}

Reply *AgileSprintEndpoint::onSetPropertyRequest()
{
    return AgileSprintEndpointProxy::onSetPropertyRequest();
}

Reply *AgileSprintEndpoint::onSwapSprintRequest()
{
    return AgileSprintEndpointProxy::onSwapSprintRequest();
}

Reply *AgileSprintEndpoint::onUpdateSprintRequest()
{
    return AgileSprintEndpointProxy::onUpdateSprintRequest();
}
