#pragma once

#include "proxies/userendpointproxy.h"

class UserEndpoint : public UserEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(UserEndpoint)

public:
    UserEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddUserToApplicationRequest() override;
    virtual Reply *onChangeUserPasswordRequest() override;
    virtual Reply *onCreateAvatarFromTemporaryRequest() override;
    virtual Reply *onCreateUserRequest() override;
    virtual Reply *onScheduleUserAnonymizationRequest() override;
    virtual Reply *onScheduleUserAnonymizationRerunRequest() override;
    virtual Reply *onSetColumnsRequest() override;
    virtual Reply *onSetPropertyRequest() override;
    virtual Reply *onStoreTemporaryAvatarRequest() override;
    virtual Reply *onStoreTemporaryAvatarUsingMultiPartRequest() override;
    virtual Reply *onUpdateProjectAvatarRequest() override;
    virtual Reply *onUpdateUserRequest() override;

protected:
    virtual QJSValueList onGetUserSuccess(const QByteArray &data) override;
    virtual QJSValueList onGetUserError(const QByteArray &) override;
};
