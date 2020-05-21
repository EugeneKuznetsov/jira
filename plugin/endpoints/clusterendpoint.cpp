#include "clusterendpoint.h"

ClusterEndpoint::ClusterEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ClusterEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ClusterEndpoint::onAcknowledgeErrorsRequest()
{
    return ClusterEndpointProxy::onAcknowledgeErrorsRequest();
}

Reply *ClusterEndpoint::onApproveUpgradeRequest()
{
    return ClusterEndpointProxy::onApproveUpgradeRequest();
}

Reply *ClusterEndpoint::onCancelUpgradeRequest()
{
    return ClusterEndpointProxy::onCancelUpgradeRequest();
}

Reply *ClusterEndpoint::onChangeNodeStateToOfflineRequest()
{
    return ClusterEndpointProxy::onChangeNodeStateToOfflineRequest();
}

Reply *ClusterEndpoint::onSetReadyToUpgradeRequest()
{
    return ClusterEndpointProxy::onSetReadyToUpgradeRequest();
}
