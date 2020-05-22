#include "dashboardendpoint.h"

DashboardEndpoint::DashboardEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : DashBoardEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *DashboardEndpoint::onSetPropertyRequest()
{
    return DashBoardEndpointProxy::onSetPropertyRequest();
}
