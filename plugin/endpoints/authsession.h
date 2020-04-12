#pragma once

#include <QObject>
#include <QJSValue>

class Session;
class Jira;

class AuthSession : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AuthSession)

    AuthSession();

public:
    AuthSession(Session *session, const QJSValue &callback, Jira *parent);

public slots:
    void login(const QString &username, const QString &password);
    void logout();
    void currentUser();

private:
    Session     *m_session;
    QJSValue    m_callback;
};
