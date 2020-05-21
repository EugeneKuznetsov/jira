#pragma once

#include "proxies/groupsendpointproxy.h"

class GroupsEndpoint : public GroupsEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(GroupsEndpoint)

public:
    GroupsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
