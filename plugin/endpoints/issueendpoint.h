#pragma once

#include "endpoint.h"

class IssueEndpoint : public Endpoint
{
    Q_DISABLE_COPY(IssueEndpoint)

public:
    IssueEndpoint(const QJSValue &jsCallback, Jira *parent);

    void getIssue(const QString &issueIdOrKey, const QString &fields, const QString &expand);
};
