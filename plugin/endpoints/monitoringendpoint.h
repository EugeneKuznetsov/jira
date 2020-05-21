#pragma once

#include "proxies/monitoringendpointproxy.h"

class MonitoringEndpoint : public MonitoringEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(MonitoringEndpoint)

public:
    MonitoringEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onStartRequest() override;
    virtual Reply *onStopRequest() override;
};
