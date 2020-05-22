#include "agileissueendpoint.h"

AgileIssueEndpoint::AgileIssueEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AgileIssueEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AgileIssueEndpoint::onEstimateIssueForBoardRequest()
{
    return AgileIssueEndpointProxy::onEstimateIssueForBoardRequest();
}

Reply *AgileIssueEndpoint::onRankIssuesRequest()
{
    return AgileIssueEndpointProxy::onRankIssuesRequest();
}
