#include "customfieldoptionendpoint.h"

CustomFieldOptionEndpoint::CustomFieldOptionEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : CustomFieldOptionEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
