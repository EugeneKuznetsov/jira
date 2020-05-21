#pragma once

#include "proxies/securitylevelendpointproxy.h"

class SecurityLevelEndpoint : public SecurityLevelEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(SecurityLevelEndpoint)

public:
    SecurityLevelEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
