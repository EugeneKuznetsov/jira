#pragma once

#include "proxies/statuscategoryendpointproxy.h"

class StatusCategoryEndpoint : public StatusCategoryEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(StatusCategoryEndpoint)

public:
    StatusCategoryEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
