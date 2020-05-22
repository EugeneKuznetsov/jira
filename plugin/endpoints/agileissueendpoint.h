#pragma once

#include "agileproxies/agileissueendpointproxy.h"

class AgileIssueEndpoint : public AgileIssueEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AgileIssueEndpoint)

public:
    AgileIssueEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onEstimateIssueForBoardRequest() override;
    virtual Reply *onRankIssuesRequest() override;
};
