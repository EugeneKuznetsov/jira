#pragma once

#include "proxies/commentendpointproxy.h"

class CommentEndpoint : public CommentEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(CommentEndpoint)

public:
    CommentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSetPropertyRequest() override;
};
