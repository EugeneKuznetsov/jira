#include "api2endpoint.h"

Api2Endpoint::Api2Endpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : Api2EndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
