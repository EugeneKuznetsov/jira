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
    , m_lastJiraError()
{
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
    else if (!m_lastJiraError.isEmpty())
        return m_lastJiraError;
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
            } else if (400 == statusCode) {
                m_lastJiraError = "Incorrect usage of REST API";
            } else {
                m_lastJiraError = "Some auth error";  // TODO: add more informatoin based on status
            }
            emit lastErrorChanged(getLastError());
        }
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{success});
        reply->deleteLater();
    });
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
    }

    return m_session;
}
