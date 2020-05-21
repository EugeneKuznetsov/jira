#include "customfieldsendpoint.h"

CustomFieldsEndpoint::CustomFieldsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : CustomFieldsEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
