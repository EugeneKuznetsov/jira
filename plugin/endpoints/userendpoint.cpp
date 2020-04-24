#include <QQmlEngine>
#include <QJsonDocument>
#include "userendpoint.h"
#include "utils/logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/jira.h"
#include "qmltypes/responsestatus.h"
#include "qmltypes/resources/user.h"

UserEndpoint::UserEndpoint(Session *session, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_session(session)
    , m_callback(callback)
    , m_baseUri("/rest/api/2/user")
{
    qCDebug(JIRA_INTERNAL) << "created new endpoint:" << this << "with session:" << session;
    if (!callback.isCallable())
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
}

void UserEndpoint::getUserByUsername(const QString &username)
{
    qCDebug(JIRA_API) << this << "username:" << username;

    getUser({{"username", username}});
}

void UserEndpoint::getUserByKey(const QString &key)
{
    qCDebug(JIRA_API) << this << "key:" << key;

    getUser({{"key", key}});
}

void UserEndpoint::getUser(const QUrlQuery &query)
{
    QUrl path(m_baseUri.toString());
    path.setQuery(query);
    Reply *reply = m_session->get(QUrl(path));
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying later:" << reply;
        reply->deleteLater();
        qCDebug(JIRA_API) << this << "self-destruction later:" << this;
        this->deleteLater();
    });
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, reply](const int statusCode, const QByteArray &data) {
        User *user = nullptr;
        if (200 == statusCode) {
            qCDebug(JIRA_API_DATA) << this << reply << "successfuly received requested Issue";
            user = new User(QJsonDocument::fromJson(data).object());
            qmlEngine(parent())->setObjectOwnership(user, QQmlEngine::JavaScriptOwnership);
            qCDebug(JIRA_API_DATA) << this << reply << "created new:" << user;
        }
        const StatusMap codes = {
            {200, true},    // a full representation of a JIRA user in JSON format
            {401, false},   // current user is not authenticated
            {404, false}    // requested user is not found
        };
        ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
        qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        m_callback.call(QJSValueList{qjsEngine(parent())->toScriptValue(status), qjsEngine(parent())->toScriptValue(user)});
    });
}
