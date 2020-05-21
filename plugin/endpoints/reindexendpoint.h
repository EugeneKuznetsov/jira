#pragma once

#include "proxies/reindexendpointproxy.h"

class ReIndexEndpoint : public ReIndexEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ReIndexEndpoint)

public:
    ReIndexEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onProcessRequestsRequest() override;
    virtual Reply *onReindexRequest() override;
    virtual Reply *onReindexIssuesRequest() override;
};
