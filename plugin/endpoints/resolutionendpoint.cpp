#include "resolutionendpoint.h"

ResolutionEndpoint::ResolutionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ResolutionEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
