#include <QQmlEngine>
#include "jira.h"
#include "utils/logging.h"
#include "network/session.h"
#include "endpoints/sessionendpoint.h"
#include "endpoints/issueendpoint.h"
#include "endpoints/searchendpoint.h"
#include "endpoints/userendpoint.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_options(new Options(this))
    , m_session(nullptr)
{
    qCDebug(JIRA_INTERNAL) << this << "was created";
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

bool Jira::login(const QJSValue &callback)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
        return false;
    }

    SessionEndpoint *endpoint = new SessionEndpoint(callback, activeSession(), this);
    endpoint->login(m_options->property("username").toString(), m_options->property("password").toString());

    return true;
}

bool Jira::issue(const QJSValue &callback, const QString &issueIdOrKey,
                 const QString &fields/* = "*all"*/, const QString &expand/* = ""*/)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
        return false;
    }

    IssueEndpoint *endpoint = new IssueEndpoint(callback, activeSession(), this);
    endpoint->getIssue(issueIdOrKey, fields, expand);

    return true;
}

bool Jira::search(const QJSValue &callback, const QString &jql, const int startAt/* = 0*/, const int maxResults/* = 50*/,
                  const QString &fields/* = "*navigable"*/, const QString &expand/* = ""*/)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
        return false;
    }

    SearchEndpoint *endpoint = new SearchEndpoint(callback, activeSession(), this);
    endpoint->search(jql, startAt, maxResults, fields, expand);

    return true;
}

bool Jira::user(const QJSValue &callback, const QString &username)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
        return false;
    }

    UserEndpoint *endpoint = new UserEndpoint(callback, activeSession(), this);
    endpoint->getUserResource(username);

    return true;
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
