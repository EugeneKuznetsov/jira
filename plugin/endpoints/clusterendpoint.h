#pragma once

#include "proxies/clusterendpointproxy.h"

class ClusterEndpoint : public ClusterEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ClusterEndpoint)

public:
    ClusterEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAcknowledgeErrorsRequest() override;
    virtual Reply *onApproveUpgradeRequest() override;
    virtual Reply *onCancelUpgradeRequest() override;
    virtual Reply *onChangeNodeStateToOfflineRequest() override;
    virtual Reply *onSetReadyToUpgradeRequest() override;
};
