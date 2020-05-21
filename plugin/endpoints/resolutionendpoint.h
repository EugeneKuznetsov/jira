#pragma once

#include "proxies/resolutionendpointproxy.h"

class ResolutionEndpoint : public ResolutionEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ResolutionEndpoint)

public:
    ResolutionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
