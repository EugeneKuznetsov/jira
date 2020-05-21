#include "monitoringendpoint.h"

MonitoringEndpoint::MonitoringEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : MonitoringEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *MonitoringEndpoint::onStartRequest()
{
    return MonitoringEndpointProxy::onStartRequest();
}

Reply *MonitoringEndpoint::onStopRequest()
{
    return MonitoringEndpointProxy::onStopRequest();
}
