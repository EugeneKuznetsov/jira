#include <QJsonDocument>
#include <QJsonObject>
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
