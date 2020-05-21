#pragma once

#include "proxies/issuetypeschemeendpointproxy.h"

class IssueTypeSchemeEndpoint : public IssueTypeSchemeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueTypeSchemeEndpoint)

public:
    IssueTypeSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddProjectAssociationsToSchemeRequest() override;
    virtual Reply *onCreateIssueTypeSchemeRequest() override;
    virtual Reply *onSetProjectAssociationsForSchemeRequest() override;
    virtual Reply *onUpdateIssueTypeSchemeRequest() override;
};
