#pragma once

#include "proxies/jqlendpointproxy.h"

class JqlEndpoint : public JqlEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(JqlEndpoint)

public:
    JqlEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
