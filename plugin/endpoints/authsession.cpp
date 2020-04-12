#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include "authsession.h"
#include "logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/responsestatus.h"
#include "qmltypes/jira.h"

AuthSession::AuthSession(Session *session, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_session(session)
    , m_callback(callback)
{
    qCDebug(JIRA_INTERNAL) << "created new endpoint:" << this << "with session:" << session;
    if (!callback.isCallable())
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
}

void AuthSession::login(const QString &username, const QString &password)
{
    qCDebug(JIRA_API) << this << "username:" << username << "password:" << password;

    QJsonObject root;
    root.insert("username", username);
    root.insert("password", password);
    QJsonDocument payload(root);

    Reply *reply = m_session->post(QUrl("/rest/auth/1/session"), payload.toJson());
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying later:" << reply;
        reply->deleteLater();
        qCDebug(JIRA_API) << this << "self-destruction later:" << this;
        this->deleteLater();
    });
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this](const int statusCode, const QByteArray &data) {
        StatusMap codes = {
            {200, true},    // success
            {401, false},   // login fails due to invalid credentials
            {403, false}    // login is denied due to a CAPTCHA requirement, throtting, or any other reason
        };
        ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
        qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        this->m_callback.call(QJSValueList{qjsEngine(parent())->toScriptValue(status)});
    });
}

void AuthSession::logout()
{
    qCWarning(JIRA_API) << "Not implemented";
}

void AuthSession::currentUser()
{
    qCWarning(JIRA_API) << "Not implemented";
}
