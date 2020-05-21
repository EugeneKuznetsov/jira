#pragma once

#include "proxies/statusendpointproxy.h"

class StatusEndpoint : public StatusEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(StatusEndpoint)

public:
    StatusEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
