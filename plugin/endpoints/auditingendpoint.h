#pragma once

#include "proxies/auditingendpointproxy.h"

class AuditingEndpoint : public AuditingEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AuditingEndpoint)

public:
    AuditingEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddRecordRequest() override;
};
