#pragma once

#include "proxies/serverinfoendpointproxy.h"

class ServerInfoEndpoint : public ServerInfoEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ServerInfoEndpoint)

public:
    ServerInfoEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
