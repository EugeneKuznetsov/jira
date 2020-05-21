#include "workflowschemeendpoint.h"

WorkflowSchemeEndpoint::WorkflowSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : WorkflowSchemeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *WorkflowSchemeEndpoint::onCreateDraftForParentRequest()
{
    return WorkflowSchemeEndpointProxy::onCreateDraftForParentRequest();
}

Reply *WorkflowSchemeEndpoint::onCreateSchemeRequest()
{
    return WorkflowSchemeEndpointProxy::onCreateSchemeRequest();
}

Reply *WorkflowSchemeEndpoint::onSetDraftIssueTypeRequest()
{
    return WorkflowSchemeEndpointProxy::onSetDraftIssueTypeRequest();
}

Reply *WorkflowSchemeEndpoint::onSetIssueTypeRequest()
{
    return WorkflowSchemeEndpointProxy::onSetIssueTypeRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateDefaultRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateDefaultRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateDraftRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateDraftRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateDraftDefaultRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateDraftDefaultRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateDraftWorkflowMappingRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateDraftWorkflowMappingRequest();
}

Reply *WorkflowSchemeEndpoint::onUpdateWorkflowMappingRequest()
{
    return WorkflowSchemeEndpointProxy::onUpdateWorkflowMappingRequest();
}
