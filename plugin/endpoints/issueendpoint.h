#pragma once

#include "endpoint.h"

class IssueEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueEndpoint)

public:
    IssueEndpoint(const QJSValue &jsCallback, Jira *parent);

public slots:
    void getIssue(const QString &issueIdOrKey, const QString &fields = "*all", const QString &expand = "");
};
