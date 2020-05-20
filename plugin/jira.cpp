#include <QNetworkAccessManager>
#include "session.h"
#include "sessionendpoint.h"
#include "issueendpoint.h"
#include "searchendpoint.h"
#include "userendpoint.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_session(nullptr)
{
}

const QUrl &Jira::getServer() const
{
    static const QUrl emptyUrl;
    return (nullptr != m_session) ? m_session->getServer() : emptyUrl;
}

void Jira::setServer(const QUrl &server)
{
    if (nullptr != m_session && m_session->getServer() == server)
        return;

    if (nullptr != m_session)
        m_session->deleteLater();

    m_session = newSession(server);
    connect(m_session, &Session::networkError, this, &Jira::networkErrorDetails);

    emit serverChanged();
}

QObject *Jira::session(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SessionEndpoint>(callback);
}

QObject *Jira::issue(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueEndpoint>(callback);
}

QObject *Jira::search(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SearchEndpoint>(callback);
}

QObject *Jira::user(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<UserEndpoint>(callback);
}

Session *Jira::newSession(const QUrl &server)
{
    return new Session(server, qmlEngine(this)->networkAccessManager(), this);
}
