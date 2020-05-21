#pragma once

#include "proxies/indexendpointproxy.h"

class IndexEndpoint : public IndexEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IndexEndpoint)

public:
    IndexEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
