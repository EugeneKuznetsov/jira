#pragma once

#include "proxies/permissionschemeendpointproxy.h"

class PermissionSchemeEndpoint : public PerMissionSchemeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(PermissionSchemeEndpoint)

public:
    PermissionSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreatePermissionGrantRequest() override;
    virtual Reply *onCreatePermissionSchemeRequest() override;
    virtual Reply *onSetSchemeAttributeRequest() override;
    virtual Reply *onUpdatePermissionSchemeRequest() override;
};
