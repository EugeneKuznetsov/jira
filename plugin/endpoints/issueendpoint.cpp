#include <QJsonDocument>
#include "issue.h"
#include "issueendpoint.h"

IssueEndpoint::IssueEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

void IssueEndpoint::getIssue(const QString &issueIdOrKey, const QString &fields/* = "*all"*/,
                             const QString &expand/* = ""*/, const QString &properties/* = ""*/, const bool updateHistory/* = false*/)
{
    IssueEndpointProxy::getIssue(issueIdOrKey, fields, expand, properties, updateHistory);
}

Reply *IssueEndpoint::onAddAttachmentRequest()
{
    return IssueEndpointProxy::onAddAttachmentRequest();
}

Reply *IssueEndpoint::onAddCommentRequest()
{
    return IssueEndpointProxy::onAddCommentRequest();
}

Reply *IssueEndpoint::onAddVoteRequest()
{
    return IssueEndpointProxy::onAddVoteRequest();
}

Reply *IssueEndpoint::onAddWatcherRequest()
{
    return IssueEndpointProxy::onAddWatcherRequest();
}

Reply *IssueEndpoint::onAddWorklogRequest()
{
    return IssueEndpointProxy::onAddWorklogRequest();
}

Reply *IssueEndpoint::onArchiveIssueRequest()
{
    return IssueEndpointProxy::onArchiveIssueRequest();
}

Reply *IssueEndpoint::onArchiveIssuesRequest()
{
    return IssueEndpointProxy::onArchiveIssuesRequest();
}

Reply *IssueEndpoint::onAssignRequest()
{
    return IssueEndpointProxy::onAssignRequest();
}

Reply *IssueEndpoint::onCreateIssueRequest()
{
    return IssueEndpointProxy::onCreateIssueRequest();
}

Reply *IssueEndpoint::onCreateIssuesRequest()
{
    return IssueEndpointProxy::onCreateIssuesRequest();
}

Reply *IssueEndpoint::onCreateOrUpdateRemoteIssueLinkRequest()
{
    return IssueEndpointProxy::onCreateOrUpdateRemoteIssueLinkRequest();
}

Reply *IssueEndpoint::onDoTransitionRequest()
{
    return IssueEndpointProxy::onDoTransitionRequest();
}

Reply *IssueEndpoint::onEditIssueRequest()
{
    return IssueEndpointProxy::onEditIssueRequest();
}

Reply *IssueEndpoint::onMoveSubTasksRequest()
{
    return IssueEndpointProxy::onMoveSubTasksRequest();
}

Reply *IssueEndpoint::onNotifyRequest()
{
    return IssueEndpointProxy::onNotifyRequest();
}

Reply *IssueEndpoint::onRestoreIssueRequest()
{
    return IssueEndpointProxy::onRestoreIssueRequest();
}

Reply *IssueEndpoint::onSetPropertyRequest()
{
    return IssueEndpointProxy::onSetPropertyRequest();
}

Reply *IssueEndpoint::onUpdateCommentRequest()
{
    return IssueEndpointProxy::onUpdateCommentRequest();
}

Reply *IssueEndpoint::onUpdateRemoteIssueLinkRequest()
{
    return IssueEndpointProxy::onUpdateRemoteIssueLinkRequest();
}

Reply *IssueEndpoint::onUpdateWorklogRequest()
{
    return IssueEndpointProxy::onUpdateWorklogRequest();
}

QJSValueList IssueEndpoint::onGetIssueSuccess(const QByteArray &data)
{
    Issue *issue = new Issue(QJsonDocument::fromJson(data).object());
    getQmlEngine()->setObjectOwnership(issue, QQmlEngine::JavaScriptOwnership);
    return QJSValueList{jsArg(issue)};
}

QJSValueList IssueEndpoint::onGetIssueError(const QByteArray &)
{
    return QJSValueList{jsArg(nullptr)};
}
