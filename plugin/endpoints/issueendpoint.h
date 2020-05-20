#pragma once

#include "proxies/issueendpointproxy.h"

class IssueEndpoint : public IssueEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueEndpoint)

public:
    IssueEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddAttachmentRequest() override;
    virtual Reply *onAddCommentRequest() override;
    virtual Reply *onAddVoteRequest() override;
    virtual Reply *onAddWatcherRequest() override;
    virtual Reply *onAddWorklogRequest() override;
    virtual Reply *onArchiveIssueRequest() override;
    virtual Reply *onArchiveIssuesRequest() override;
    virtual Reply *onAssignRequest() override;
    virtual Reply *onCreateIssueRequest() override;
    virtual Reply *onCreateIssuesRequest() override;
    virtual Reply *onCreateOrUpdateRemoteIssueLinkRequest() override;
    virtual Reply *onDoTransitionRequest() override;
    virtual Reply *onEditIssueRequest() override;
    virtual Reply *onMoveSubTasksRequest() override;
    virtual Reply *onNotifyRequest() override;
    virtual Reply *onRestoreIssueRequest() override;
    virtual Reply *onSetPropertyRequest() override;
    virtual Reply *onUpdateCommentRequest() override;
    virtual Reply *onUpdateRemoteIssueLinkRequest() override;
    virtual Reply *onUpdateWorklogRequest() override;

protected:
    virtual QJSValueList onGetIssueSuccess(const QByteArray &data) override;
    virtual QJSValueList onGetIssueError(const QByteArray &) override;
};
