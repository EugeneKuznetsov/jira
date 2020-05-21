#include "universalavatarendpoint.h"

UniversalAvatarEndpoint::UniversalAvatarEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : Universal_AvatarEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *UniversalAvatarEndpoint::onCreateAvatarFromTemporaryRequest()
{
    return Universal_AvatarEndpointProxy::onCreateAvatarFromTemporaryRequest();
}

Reply *UniversalAvatarEndpoint::onStoreTemporaryAvatarRequest()
{
    return Universal_AvatarEndpointProxy::onStoreTemporaryAvatarRequest();
}

Reply *UniversalAvatarEndpoint::onStoreTemporaryAvatarUsingMultiPartRequest()
{
    return Universal_AvatarEndpointProxy::onStoreTemporaryAvatarUsingMultiPartRequest();
}
