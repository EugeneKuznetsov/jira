#include "fieldendpoint.h"

FieldEndpoint::FieldEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : FieldEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *FieldEndpoint::onCreateCustomFieldRequest()
{
    return FieldEndpointProxy::onCreateCustomFieldRequest();
}
