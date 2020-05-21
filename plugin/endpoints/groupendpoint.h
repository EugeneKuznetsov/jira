#pragma once

#include "proxies/groupendpointproxy.h"

class GroupEndpoint : public GroupEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(GroupEndpoint)

public:
    GroupEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddUserToGroupRequest() override;
    virtual Reply *onCreateGroupRequest() override;
};
