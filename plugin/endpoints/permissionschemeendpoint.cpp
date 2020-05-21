#include "permissionschemeendpoint.h"

PermissionSchemeEndpoint::PermissionSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : PerMissionSchemeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *PermissionSchemeEndpoint::onCreatePermissionGrantRequest()
{
    return PerMissionSchemeEndpointProxy::onCreatePermissionGrantRequest();
}

Reply *PermissionSchemeEndpoint::onCreatePermissionSchemeRequest()
{
    return PerMissionSchemeEndpointProxy::onCreatePermissionSchemeRequest();
}

Reply *PermissionSchemeEndpoint::onSetSchemeAttributeRequest()
{
    return PerMissionSchemeEndpointProxy::onSetSchemeAttributeRequest();
}

Reply *PermissionSchemeEndpoint::onUpdatePermissionSchemeRequest()
{
    return PerMissionSchemeEndpointProxy::onUpdatePermissionSchemeRequest();
}
