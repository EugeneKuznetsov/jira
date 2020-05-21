#pragma once

#include "proxies/passwordendpointproxy.h"

class PasswordEndpoint : public PasswordEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(PasswordEndpoint)

public:
    PasswordEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onPolicyCheckCreateUserRequest() override;
    virtual Reply *onPolicyCheckUpdateUserRequest() override;
};
