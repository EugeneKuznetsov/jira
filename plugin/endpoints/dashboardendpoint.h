#pragma once

#include "proxies/dashboardendpointproxy.h"

class DashboardEndpoint : public DashboardEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(DashboardEndpoint)

public:
    DashboardEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSetPropertyRequest() override;
};
