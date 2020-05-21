#include "passwordendpoint.h"

PasswordEndpoint::PasswordEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : PasswordEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *PasswordEndpoint::onPolicyCheckCreateUserRequest()
{
    return PasswordEndpointProxy::onPolicyCheckCreateUserRequest();
}

Reply *PasswordEndpoint::onPolicyCheckUpdateUserRequest()
{
    return PasswordEndpointProxy::onPolicyCheckUpdateUserRequest();
}
