#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "serverinfoendpoint.h"

ServerInfoEndpoint::ServerInfoEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ServerInfoEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

void ServerInfoEndpoint::getServerInfo(const bool doHealthCheck/* = false*/)
{
    ServerInfoEndpointProxy::getServerInfo(doHealthCheck);
}
