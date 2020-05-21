#include "projectvalidateendpoint.h"

ProjectValidateEndpoint::ProjectValidateEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ProjectValidateEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
