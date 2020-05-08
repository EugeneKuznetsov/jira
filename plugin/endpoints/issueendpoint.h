#pragma once

#include "endpoint.h"

class IssueEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueEndpoint)

public:
    IssueEndpoint(const QJSValue &jsCallback, Session *session, Jira *parent);

    void getIssue(const QString &issueIdOrKey, const QString &fields, const QString &expand);
};
