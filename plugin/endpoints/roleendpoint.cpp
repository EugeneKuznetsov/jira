#include "roleendpoint.h"

RoleEndpoint::RoleEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : RoleEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *RoleEndpoint::onAddProjectRoleActorsToRoleRequest()
{
    return RoleEndpointProxy::onAddProjectRoleActorsToRoleRequest();
}

Reply *RoleEndpoint::onCreateProjectRoleRequest()
{
    return RoleEndpointProxy::onCreateProjectRoleRequest();
}

Reply *RoleEndpoint::onFullyUpdateProjectRoleRequest()
{
    return RoleEndpointProxy::onFullyUpdateProjectRoleRequest();
}

Reply *RoleEndpoint::onPartialUpdateProjectRoleRequest()
{
    return RoleEndpointProxy::onPartialUpdateProjectRoleRequest();
}
