#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include "sessionendpoint.h"
#include "logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/responsestatus.h"
#include "qmltypes/jira.h"

SessionEndpoint::SessionEndpoint(Session *session, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_session(session)
    , m_callback(callback)
    , m_baseUri("/rest/auth/1/session")
{
    qCDebug(JIRA_INTERNAL) << "created new endpoint:" << this << "with session:" << session;
    if (!callback.isCallable())
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
}

void SessionEndpoint::login(const QString &username, const QString &password)
{
    qCDebug(JIRA_API) << this << "username:" << username << "password:" << password;

    QJsonObject root;
    root.insert("username", username);
    root.insert("password", password);
    QJsonDocument payload(root);

    Reply *reply = m_session->post(m_baseUri, payload.toJson());
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying later:" << reply;
        reply->deleteLater();
        qCDebug(JIRA_API) << this << "self-destruction later:" << this;
        this->deleteLater();
    });
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this](const int statusCode, const QByteArray &data) {
        const StatusMap codes = {
            {200, true},    // information about the caller's session if the caller is authenticated
            {401, false},   // login fails due to invalid credentials
            {403, false}    // login is denied due to a CAPTCHA requirement, throtting, or any other reason
        };
        ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
        qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        m_callback.call(QJSValueList{qjsEngine(parent())->toScriptValue(status)});
    });
}

void SessionEndpoint::logout()
{
    qCWarning(JIRA_API) << "Not implemented";
}

void SessionEndpoint::currentUser()
{
    qCWarning(JIRA_API) << "Not implemented";
}
