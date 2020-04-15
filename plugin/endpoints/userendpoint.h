#pragma once

#include <QObject>
#include <QUrlQuery>
#include <QJSValue>
#include <QUrl>

class Session;
class Jira;

class UserEndpoint : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(UserEndpoint)

    UserEndpoint();

public:
    explicit UserEndpoint(Session *session, const QJSValue &callback, Jira *parent);

    void getUserByUsername(const QString &username);
    void getUserByKey(const QString &key);

private:
    void getUser(const QUrlQuery &query);

private:
    Session     *m_session;
    QJSValue    m_callback;
    const QUrl  m_baseUri;
};
