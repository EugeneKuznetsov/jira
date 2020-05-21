#include "versionendpoint.h"

VersionEndpoint::VersionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : VersionEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *VersionEndpoint::onCreateOrUpdateRemoteVersionLink_1PRequest()
{
    return VersionEndpointProxy::onCreateOrUpdateRemoteVersionLink_1PRequest();
}

Reply *VersionEndpoint::onCreateOrUpdateRemoteVersionLink_2PRequest()
{
    return VersionEndpointProxy::onCreateOrUpdateRemoteVersionLink_2PRequest();
}

Reply *VersionEndpoint::onCreateVersionRequest()
{
    return VersionEndpointProxy::onCreateVersionRequest();
}

Reply *VersionEndpoint::onDelete_1PRequest()
{
    return VersionEndpointProxy::onDelete_1PRequest();
}

Reply *VersionEndpoint::onMergeRequest()
{
    return VersionEndpointProxy::onMergeRequest();
}

Reply *VersionEndpoint::onMoveVersionRequest()
{
    return VersionEndpointProxy::onMoveVersionRequest();
}

Reply *VersionEndpoint::onUpdateVersionRequest()
{
    return VersionEndpointProxy::onUpdateVersionRequest();
}
