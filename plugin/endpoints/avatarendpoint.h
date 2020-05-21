#pragma once

#include "proxies/avatarendpointproxy.h"

class AvatarEndpoint : public AvatarEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AvatarEndpoint)

public:
    AvatarEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateAvatarFromTemporaryRequest() override;
    virtual Reply *onStoreTemporaryAvatarRequest() override;
};
