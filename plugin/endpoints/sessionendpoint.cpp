#include <QJsonDocument>
#include <QJsonObject>
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/jira.h"
#include "utils/logging.h"
#include "sessionendpoint.h"

SessionEndpoint::SessionEndpoint(const QJSValue &jsCallback, Session *session, Jira *parent)
    : Endpoint(QUrl("/rest/auth/1/session"), jsCallback, session, parent)
{
}

void SessionEndpoint::login(const QString &username, const QString &password)
{
    QJsonDocument payload({{"username", username}, {"password", password}});
    connect(post(payload.toJson()), &Reply::ready, [this](const int statusCode, const QByteArray &data) {
        const StatusMap codes = {
            {200, true},    // information about the caller's session if the caller is authenticated
            {401, false},   // login fails due to invalid credentials
            {403, false}    // login is denied due to a CAPTCHA requirement, throtting, or any other reason
        };
        callback(statusCode, data, codes);
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
