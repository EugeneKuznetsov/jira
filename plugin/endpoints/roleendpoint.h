#pragma once

#include "proxies/roleendpointproxy.h"

class RoleEndpoint : public RoleEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(RoleEndpoint)

public:
    RoleEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddProjectRoleActorsToRoleRequest() override;
    virtual Reply *onCreateProjectRoleRequest() override;
    virtual Reply *onFullyUpdateProjectRoleRequest() override;
    virtual Reply *onPartialUpdateProjectRoleRequest() override;
};
