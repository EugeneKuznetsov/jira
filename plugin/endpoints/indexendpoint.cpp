#include "indexendpoint.h"

IndexEndpoint::IndexEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IndexEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
