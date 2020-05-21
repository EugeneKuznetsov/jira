#pragma once

#include "proxies/customfieldoptionendpointproxy.h"

class CustomFieldOptionEndpoint : public CustomFieldOptionEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(CustomFieldOptionEndpoint)

public:
    CustomFieldOptionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
