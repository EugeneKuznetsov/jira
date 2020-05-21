#pragma once

#include "proxies/fieldendpointproxy.h"

class FieldEndpoint : public FieldEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(FieldEndpoint)

public:
    FieldEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateCustomFieldRequest() override;
};
