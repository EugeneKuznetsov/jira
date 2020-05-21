#pragma once

#include "proxies/myselfendpointproxy.h"

class MySelfEndpoint : public MySelfEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(MySelfEndpoint)

public:
    MySelfEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onChangeMyPasswordRequest() override;
    virtual Reply *onUpdateUserRequest() override;
};
