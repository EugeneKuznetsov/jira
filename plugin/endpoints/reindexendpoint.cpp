#include "reindexendpoint.h"

ReIndexEndpoint::ReIndexEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ReIndexEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ReIndexEndpoint::onProcessRequestsRequest()
{
    return ReIndexEndpointProxy::onProcessRequestsRequest();
}

Reply *ReIndexEndpoint::onReindexRequest()
{
    return ReIndexEndpointProxy::onReindexRequest();
}

Reply *ReIndexEndpoint::onReindexIssuesRequest()
{
    return ReIndexEndpointProxy::onReindexIssuesRequest();
}
