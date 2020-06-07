#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "network/session.h"
#include "sessionendpoint.h"

SessionEndpoint::SessionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : SessionEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *SessionEndpoint::onLoginRequest()
{
    QJsonDocument payload({{"username", m_username}, {"password", m_password}});
    return httpPost(payload.toJson());
}

QJSValueList SessionEndpoint::onCurrentUserSuccess(const QByteArray &data)
{
    QJsonDocument json = QJsonDocument::fromJson(data);
    if (json.isNull())
        return {jsArg(nullptr)};
    else
        return {json.isObject() ? jsArg(json.object()) : jsArg(json.array())};
}
