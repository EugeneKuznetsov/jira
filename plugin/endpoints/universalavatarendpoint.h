#pragma once

#include "proxies/universal_avatarendpointproxy.h"

class UniversalAvatarEndpoint : public Universal_AvatarEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(UniversalAvatarEndpoint)

public:
    UniversalAvatarEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateAvatarFromTemporaryRequest() override;
    virtual Reply *onStoreTemporaryAvatarRequest() override;
    virtual Reply *onStoreTemporaryAvatarUsingMultiPartRequest() override;
};
