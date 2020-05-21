#include "groupendpoint.h"

GroupEndpoint::GroupEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : GroupEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *GroupEndpoint::onAddUserToGroupRequest()
{
    return GroupEndpointProxy::onAddUserToGroupRequest();
}

Reply *GroupEndpoint::onCreateGroupRequest()
{
    return GroupEndpointProxy::onCreateGroupRequest();
}
