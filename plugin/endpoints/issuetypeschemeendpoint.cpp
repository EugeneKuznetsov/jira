#include "issuetypeschemeendpoint.h"

IssueTypeSchemeEndpoint::IssueTypeSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueTypeSchemeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *IssueTypeSchemeEndpoint::onAddProjectAssociationsToSchemeRequest()
{
    return IssueTypeSchemeEndpointProxy::onAddProjectAssociationsToSchemeRequest();
}

Reply *IssueTypeSchemeEndpoint::onCreateIssueTypeSchemeRequest()
{
    return IssueTypeSchemeEndpointProxy::onCreateIssueTypeSchemeRequest();
}

Reply *IssueTypeSchemeEndpoint::onSetProjectAssociationsForSchemeRequest()
{
    return IssueTypeSchemeEndpointProxy::onSetProjectAssociationsForSchemeRequest();
}

Reply *IssueTypeSchemeEndpoint::onUpdateIssueTypeSchemeRequest()
{
    return IssueTypeSchemeEndpointProxy::onUpdateIssueTypeSchemeRequest();
}
