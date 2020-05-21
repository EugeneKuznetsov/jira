#pragma once

#include "proxies/api2endpointproxy.h"

class Api2Endpoint : public Api2EndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(Api2Endpoint)

public:
    Api2Endpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
