#include "serverinfoendpoint.h"

ServerInfoEndpoint::ServerInfoEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ServerInfoEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
