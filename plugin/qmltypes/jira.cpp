#include <QQmlEngine>
#include "jira.h"
#include "logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "endpoints/sessionendpoint.h"
#include "endpoints/issueendpoint.h"
#include "endpoints/searchendpoint.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_options(new Options(this))
    , m_session(nullptr)
{
    qDebug(JIRA_INTERNAL) << this << "was created";
}

Options *Jira::getOptions() const
{
    return m_options;
}

void Jira::setOptions(Options *new_value)
{
    if (nullptr == new_value)
        return;

    if (nullptr != m_options && QQmlEngine::CppOwnership == qmlEngine(this)->objectOwnership(m_options))
        delete m_options;

    m_options = new_value;

    Q_UNUSED(activeSession(true));

    emit optionsChanged();
}

void Jira::login(const QJSValue &callback)
{
    SessionEndpoint *endpoint = new SessionEndpoint(activeSession(), callback, this);
    endpoint->login(m_options->property("username").toString(), m_options->property("password").toString());
}

void Jira::issue(const QJSValue &callback, const QString &issueIdOrKey,
                 const QString &fields/* = "*all"*/, const QString &expand/* = ""*/)
{
    IssueEndpoint *endpoint = new IssueEndpoint(activeSession(), callback, this);
    endpoint->getIssue(issueIdOrKey, fields, expand);
}

void Jira::search(const QJSValue &callback, const QString &jql, const int startAt/* = 0*/, const int maxResults/* = 50*/,
                  const QString &fields/* = "*navigable"*/, const QString &expand/* = ""*/)
{
    SearchEndpoint *endpoint = new SearchEndpoint(activeSession(), callback, this);
    endpoint->search(jql, startAt, maxResults, fields, expand);
}

Session *Jira::activeSession(bool createNewSession/* = false*/)
{
    if (createNewSession) {
        qCDebug(JIRA_INTERNAL) << this << "Requested creation of a new session";
        if (nullptr != m_session) {
            qCDebug(JIRA_INTERNAL) << this << "Old session will be deleted:" << m_session;
            delete m_session;
            m_session = nullptr;
        }
    }

    if (nullptr == m_session) {
        QQmlEngine *engine = qmlEngine(this);
        m_session = new Session(m_options->property("server").toUrl(), engine->networkAccessManager(), this);
        qCDebug(JIRA_INTERNAL) << "New session was created:" << m_session;
        QObject::connect(m_options, &Options::serverChanged, m_session, &Session::setServer);
    }

    return m_session;
}
