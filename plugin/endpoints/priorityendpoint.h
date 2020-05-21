#pragma once

#include "proxies/priorityendpointproxy.h"

class PriorityEndpoint : public PriorityEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(PriorityEndpoint)

public:
    PriorityEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
