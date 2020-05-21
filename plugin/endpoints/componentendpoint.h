#pragma once

#include "proxies/componentendpointproxy.h"

class ComponentEndpoint : public ComponentEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ComponentEndpoint)

public:
    ComponentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateComponentRequest() override;
    virtual Reply *onUpdateComponentRequest() override;
};
