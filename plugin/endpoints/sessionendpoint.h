#pragma once

#include <QObject>
#include <QJSValue>
#include <QUrl>

class Session;
class Jira;

class SessionEndpoint : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(SessionEndpoint)

    SessionEndpoint();

public:
    SessionEndpoint(Session *session, const QJSValue &callback, Jira *parent);

public slots:
    void login(const QString &username, const QString &password);
    void logout();
    void currentUser();

private:
    Session     *m_session;
    QJSValue    m_callback;
    const QUrl  m_baseUri;
};
