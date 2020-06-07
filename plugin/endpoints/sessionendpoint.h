#pragma once

#include "proxies/sessionendpointproxy.h"

class Session;

class SessionEndpoint : public SessionEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(SessionEndpoint)
    Q_PROPERTY(QString username MEMBER m_username NOTIFY usernameChanged)
    Q_PROPERTY(QString password MEMBER m_password NOTIFY passwordChanged)

public:
    SessionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

signals:
    void usernameChanged();
    void passwordChanged();

protected:
    virtual Reply *onLoginRequest() override;

    virtual QJSValueList onCurrentUserSuccess(const QByteArray &data) override;

private:
    QString m_username;
    QString m_password;
};
