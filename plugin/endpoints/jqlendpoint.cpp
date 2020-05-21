#include "jqlendpoint.h"

JqlEndpoint::JqlEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : JqlEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
