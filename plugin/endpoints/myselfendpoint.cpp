#include "myselfendpoint.h"

MySelfEndpoint::MySelfEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : MySelfEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *MySelfEndpoint::onChangeMyPasswordRequest()
{
    return MySelfEndpointProxy::onChangeMyPasswordRequest();
}

Reply *MySelfEndpoint::onUpdateUserRequest()
{
    return MySelfEndpointProxy::onUpdateUserRequest();
}
