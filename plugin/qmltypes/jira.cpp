#include <QNetworkAccessManager>
#include "utils/logging.h"
#include "network/session.h"
#include "endpoints/sessionendpoint.h"
#include "endpoints/issueendpoint.h"
#include "endpoints/searchendpoint.h"
#include "endpoints/userendpoint.h"
#include "jira.h"

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
        if (nullptr == engine) {
            qCWarning(JIRA_INTERNAL) << "Could not obtain QML Engine. Creating a new network access manager.";
            m_session = new Session(m_options->property("server").toUrl(), new QNetworkAccessManager(this), this);
        } else {
            m_session = new Session(m_options->property("server").toUrl(), engine->networkAccessManager(), this);
        }
        qCDebug(JIRA_INTERNAL) << "New session was created:" << m_session;
        QObject::connect(m_options, &Options::serverChanged, m_session, &Session::setServer);
    }

    return m_session;
}
