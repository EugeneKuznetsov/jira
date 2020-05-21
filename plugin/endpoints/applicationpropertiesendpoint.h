#pragma once

#include "proxies/applicationpropertiesendpointproxy.h"

class ApplicationPropertiesEndpoint : public ApplicationPropertiesEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ApplicationPropertiesEndpoint)

public:
    ApplicationPropertiesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSetPropertyViaRestfulTableRequest() override;
};
