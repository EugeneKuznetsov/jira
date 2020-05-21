#pragma once

#include "proxies/versionendpointproxy.h"

class VersionEndpoint : public VersionEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(VersionEndpoint)

public:
    VersionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateOrUpdateRemoteVersionLink_1PRequest() override;
    virtual Reply *onCreateOrUpdateRemoteVersionLink_2PRequest() override;
    virtual Reply *onCreateVersionRequest() override;
    virtual Reply *onDelete_1PRequest() override;
    virtual Reply *onMergeRequest() override;
    virtual Reply *onMoveVersionRequest() override;
    virtual Reply *onUpdateVersionRequest() override;
};
