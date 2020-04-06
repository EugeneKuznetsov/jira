#include <QJsonDocument>
#include <QJsonObject>
#include <QJSEngine>
#include <QJSValueList>
#include <QVariant>
#include <QQmlEngine>
#include "network/session.h"
#include "network/reply.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_options(new Options(this))
    , m_session(nullptr)
    , m_lastNetworkError()
    , m_lastJiraApiError()
    , m_lastJiraUserError()
    , m_currentErrorType(NO_ERROR)
{
}

Options *Jira::getOptions() const
{
    return m_options;
}

void Jira::setOptions(Options *new_value)
{
    if (nullptr == new_value)
        return;

    if (nullptr != m_options)
        delete m_options;

    m_options = new_value;
    m_options->setParent(this);

    if (nullptr == activeSession(true)) // TODO: is there a better way?
        return;

    emit optionsChanged();
}

const QString Jira::getLastError() const
{
    if (!m_lastNetworkError.isEmpty())
        return m_lastNetworkError;
    else if (!m_lastJiraApiError.isEmpty())
        return m_lastJiraApiError;
    else if (!m_lastJiraUserError.isEmpty())
        return m_lastJiraUserError;
    else
        return "";
}

void Jira::login(const QJSValue &callback)
{
    if (!callback.isCallable()) // TODO: handle error case properly
        return;

    QJsonObject root;
    root.insert("username", m_options->property("username").toString());
    root.insert("password", m_options->property("password").toString());
    QJsonDocument payload(root);
    Reply *reply = activeSession()->post(QUrl("/rest/auth/1/session"), payload.toJson());
    connect(reply, &Reply::ready, this, [this, callback, reply](const int statusCode, const QByteArray &) {
        bool success = (200 == statusCode);
        if (!success) {
            if (0 == statusCode) {
                m_lastNetworkError = reply->getErrorString();
                m_currentErrorType = NETWORK_ERROR;
            } else if (400 == statusCode) {
                m_lastJiraApiError = "Incorrect usage of REST API"; // TODO: get more details
                m_currentErrorType = JIRA_API_ERROR;
            } else {
                m_lastJiraUserError = "Some auth error";  // TODO: add more informatoin based on status
                m_currentErrorType = JIRA_USER_ERROR;
            }
            emit lastErrorChanged(getLastError());
        }
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{success});
        reply->deleteLater();
    });
}

void Jira::issue(const QString &issueIdOrKey, const QJSValue &callback)
{
    if (!callback.isCallable()) // TODO: handle error case properly
        return;

    QString path = "/rest/api/2/issue/" + issueIdOrKey;
    Reply *reply = activeSession()->get(QUrl(path));
    connect(reply, &Reply::ready, this, [this, callback, reply](const int statusCode, const QByteArray &data) {
        QJSValue callbackCopy(callback);
        bool success = (200 == statusCode);
        if (!success) {
            if (0 == statusCode) {
                m_lastNetworkError = reply->getErrorString();
                m_currentErrorType = NETWORK_ERROR;
                emit lastErrorChanged(getLastError());
            } else if (400 == statusCode) {
                m_lastJiraApiError = "Incorrect usage of REST API"; // TODO: get more details
                m_currentErrorType = JIRA_API_ERROR;
                emit lastErrorChanged(getLastError());
            } else if (404 == statusCode) {
                callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(nullptr)});
            } else {
                m_lastJiraUserError = "Some other error";  // TODO: add more informatoin based on status
                m_currentErrorType = JIRA_USER_ERROR;
                emit lastErrorChanged(getLastError());
            }
        } else {
            Issue issue(QJsonDocument::fromJson(data));
            qmlEngine(this)->setObjectOwnership(&issue, QQmlEngine::JavaScriptOwnership);   // now it is not our "headache" anymore ... ;-)
            callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(&issue)});
        }
        reply->deleteLater();
    });
}

Jira::ErrorTypes Jira::getCurrentErrorType() const
{
    return m_currentErrorType;
}

Session *Jira::activeSession(bool createNewSession/* = false*/)
{
    if (createNewSession) {
        delete m_session;
        m_session = nullptr;
    }

    if (nullptr == m_session) {
        QQmlEngine *engine = qmlEngine(this);
        Q_ASSERT(nullptr != engine);
        if (nullptr == engine)  // TODO: handle error case properly
            return nullptr;
        m_session = new Session(m_options->property("server").toUrl(), engine->networkAccessManager(), this);
        QObject::connect(m_options, &Options::serverChanged, m_session, &Session::setServer);
    }

    m_currentErrorType = NO_ERROR;

    return m_session;
}
