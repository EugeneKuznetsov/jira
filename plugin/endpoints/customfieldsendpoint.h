#pragma once

#include "proxies/customfieldsendpointproxy.h"

class CustomFieldsEndpoint : public CustomFieldsEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(CustomFieldsEndpoint)

public:
    CustomFieldsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
