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

    if (nullptr != m_options && QQmlEngine::CppOwnership == qmlEngine(this)->objectOwnership(m_options))
        delete m_options;

    m_options = new_value;

    Q_UNUSED(activeSession(true));

    emit optionsChanged();
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
    connect(reply, &Reply::destroy, this, [reply]() { reply->deleteLater(); });
    connect(reply, &Reply::networkError, this, &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [callback](const int statusCode, const QByteArray &) {
        bool success = (200 == statusCode);
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{success});
    });
}

void Jira::issue(const QString &issueIdOrKey, const QJSValue &callback)
{
    if (!callback.isCallable()) // TODO: handle error case properly
        return;

    QString path = "/rest/api/2/issue/" + issueIdOrKey;
    Reply *reply = activeSession()->get(QUrl(path));
    connect(reply, &Reply::destroy, this, [reply]() { reply->deleteLater(); });
    connect(reply, &Reply::networkError, this, &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, callback](const int statusCode, const QByteArray &data) {
        QJSValue callbackCopy(callback);
        if (404 == statusCode) {
            callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(nullptr)});
        } else if (200 == statusCode) {
            Issue issue(QJsonDocument::fromJson(data));
            qmlEngine(this)->setObjectOwnership(&issue, QQmlEngine::JavaScriptOwnership);   // now it is not our "headache" anymore ... ;-)
            callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(&issue)});
        }
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
        m_session = new Session(m_options->property("server").toUrl(), engine->networkAccessManager(), this);
        QObject::connect(m_options, &Options::serverChanged, m_session, &Session::setServer);
    }

    return m_session;
}
