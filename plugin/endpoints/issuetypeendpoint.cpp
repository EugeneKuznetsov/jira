#include "issuetypeendpoint.h"

IssueTypeEndpoint::IssueTypeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueTypeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *IssueTypeEndpoint::onCreateAvatarFromTemporaryRequest()
{
    return IssueTypeEndpointProxy::onCreateAvatarFromTemporaryRequest();
}

Reply *IssueTypeEndpoint::onCreateIssueTypeRequest()
{
    return IssueTypeEndpointProxy::onCreateIssueTypeRequest();
}

Reply *IssueTypeEndpoint::onSetPropertyRequest()
{
    return IssueTypeEndpointProxy::onSetPropertyRequest();
}

Reply *IssueTypeEndpoint::onStoreTemporaryAvatarRequest()
{
    return IssueTypeEndpointProxy::onStoreTemporaryAvatarRequest();
}

Reply *IssueTypeEndpoint::onStoreTemporaryAvatarUsingMultiPartRequest()
{
    return IssueTypeEndpointProxy::onStoreTemporaryAvatarUsingMultiPartRequest();
}

Reply *IssueTypeEndpoint::onUpdateIssueTypeRequest()
{
    return IssueTypeEndpointProxy::onUpdateIssueTypeRequest();
}
