#include "auditingendpoint.h"

AuditingEndpoint::AuditingEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AuditingEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AuditingEndpoint::onAddRecordRequest()
{
    return AuditingEndpointProxy::onAddRecordRequest();
}
