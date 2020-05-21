#include <QJsonDocument>
#include "user.h"
#include "userendpoint.h"

UserEndpoint::UserEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : UserEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *UserEndpoint::onAddUserToApplicationRequest()
{
    return UserEndpointProxy::onAddUserToApplicationRequest();
}

Reply *UserEndpoint::onChangeUserPasswordRequest()
{
    return UserEndpointProxy::onChangeUserPasswordRequest();
}

Reply *UserEndpoint::onCreateAvatarFromTemporaryRequest()
{
    return UserEndpointProxy::onCreateAvatarFromTemporaryRequest();
}

Reply *UserEndpoint::onCreateUserRequest()
{
    return UserEndpointProxy::onCreateUserRequest();
}

Reply *UserEndpoint::onScheduleUserAnonymizationRequest()
{
    return UserEndpointProxy::onScheduleUserAnonymizationRequest();
}

Reply *UserEndpoint::onScheduleUserAnonymizationRerunRequest()
{
    return UserEndpointProxy::onScheduleUserAnonymizationRerunRequest();
}

Reply *UserEndpoint::onSetColumnsRequest()
{
    return UserEndpointProxy::onSetColumnsRequest();
}

Reply *UserEndpoint::onSetPropertyRequest()
{
    return UserEndpointProxy::onSetPropertyRequest();
}

Reply *UserEndpoint::onStoreTemporaryAvatarRequest()
{
    return UserEndpointProxy::onStoreTemporaryAvatarRequest();
}

Reply *UserEndpoint::onStoreTemporaryAvatarUsingMultiPartRequest()
{
    return UserEndpointProxy::onStoreTemporaryAvatarUsingMultiPartRequest();
}

Reply *UserEndpoint::onUpdateProjectAvatarRequest()
{
    return UserEndpointProxy::onUpdateProjectAvatarRequest();
}

Reply *UserEndpoint::onUpdateUserRequest()
{
    return UserEndpointProxy::onUpdateUserRequest();
}

QJSValueList UserEndpoint::onGetUserSuccess(const QByteArray &data)
{
    User *user = new User(QJsonDocument::fromJson(data).object());
    getQmlEngine()->setObjectOwnership(user, QQmlEngine::JavaScriptOwnership);
    return QJSValueList{jsArg(user)};
}

QJSValueList UserEndpoint::onGetUserError(const QByteArray &)
{
    return QJSValueList{jsArg(nullptr)};
}
