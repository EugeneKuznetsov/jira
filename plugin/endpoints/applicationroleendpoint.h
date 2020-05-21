#pragma once

#include "proxies/applicationroleendpointproxy.h"

class ApplicationRoleEndpoint : public ApplicationRoleEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ApplicationRoleEndpoint)

public:
    ApplicationRoleEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onPutRequest() override;
    virtual Reply *onPutBulkRequest() override;
};
