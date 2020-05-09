#include <QUrlQuery>
#include <QJsonDocument>
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/external/user.h"
#include "qmltypes/jira.h"
#include "userendpoint.h"

UserEndpoint::UserEndpoint(const QJSValue &jsCallback, Jira *parent)
    : Endpoint(QUrl("/rest/api/2/user"), jsCallback, parent)
{
}

void UserEndpoint::getUserResource(const QString &username)
{
    const QUrlQuery query({{"username", username}});
    connect(get(query), &Reply::ready, [this](const int statusCode, const QByteArray &data) {
        User *user = nullptr;
        if (200 == statusCode) {
            user = new User(QJsonDocument::fromJson(data).object());
            qmlEngine(parent())->setObjectOwnership(user, QQmlEngine::JavaScriptOwnership);
        }
        const StatusMap codes = {
            {200, true},    // a full representation of a JIRA user in JSON format
            {401, false},   // current user is not authenticated
            {404, false}    // requested user is not found
        };
        callback(statusCode, data, codes, QJSValueList{jsArg(user)});
    });
}
