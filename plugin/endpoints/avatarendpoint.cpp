#include "avatarendpoint.h"

AvatarEndpoint::AvatarEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AvatarEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AvatarEndpoint::onCreateAvatarFromTemporaryRequest()
{
    return AvatarEndpointProxy::onCreateAvatarFromTemporaryRequest();
}

Reply *AvatarEndpoint::onStoreTemporaryAvatarRequest()
{
    return AvatarEndpointProxy::onStoreTemporaryAvatarRequest();
}
