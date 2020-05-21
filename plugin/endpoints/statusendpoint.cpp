#include "statusendpoint.h"

StatusEndpoint::StatusEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : StatusEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
