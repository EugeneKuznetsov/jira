#include "dashboardendpoint.h"

DashboardEndpoint::DashboardEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : DashboardEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *DashboardEndpoint::onSetPropertyRequest()
{
    return DashboardEndpointProxy::onSetPropertyRequest();
}
