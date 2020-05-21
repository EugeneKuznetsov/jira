#include "websudoendpoint.h"

WebsudoEndpoint::WebsudoEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : WebsudoEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
