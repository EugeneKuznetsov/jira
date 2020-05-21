#pragma once

#include "proxies/websudoendpointproxy.h"

class WebsudoEndpoint : public WebsudoEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(WebsudoEndpoint)

public:
    WebsudoEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
