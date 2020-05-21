#pragma once

#include "proxies/workflowschemeendpointproxy.h"

class WorkflowSchemeEndpoint : public WorkflowSchemeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(WorkflowSchemeEndpoint)

public:
    WorkflowSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateDraftForParentRequest() override;
    virtual Reply *onCreateSchemeRequest() override;
    virtual Reply *onSetDraftIssueTypeRequest() override;
    virtual Reply *onSetIssueTypeRequest() override;
    virtual Reply *onUpdateRequest() override;
    virtual Reply *onUpdateDefaultRequest() override;
    virtual Reply *onUpdateDraftRequest() override;
    virtual Reply *onUpdateDraftDefaultRequest() override;
    virtual Reply *onUpdateDraftWorkflowMappingRequest() override;
    virtual Reply *onUpdateWorkflowMappingRequest() override;
};
