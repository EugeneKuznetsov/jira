#include <QJsonDocument>
#include <QUrlQuery>
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/external/issue.h"
#include "qmltypes/jira.h"
#include "issueendpoint.h"

IssueEndpoint::IssueEndpoint(const QJSValue &jsCallback, Jira *parent)
    : Endpoint(QUrl("/rest/api/2/issue"), jsCallback, parent)
{
}

void IssueEndpoint::getIssue(const QString &issueIdOrKey, const QString &fields/* = "*all"*/, const QString &expand/* = ""*/)
{
    const QString queryPrefix = "/" + issueIdOrKey;
    const QUrlQuery query({{"fields", fields}, {"expand", expand}});
    connect(get(queryPrefix, query), &Reply::ready, [this](const int statusCode, const QByteArray &data) {
        Issue *issue = nullptr;
        if (200 == statusCode) {
            issue = new Issue(QJsonDocument::fromJson(data).object());
            qmlEngine(parent())->setObjectOwnership(issue, QQmlEngine::JavaScriptOwnership);
        }
        const StatusMap codes = {
            {200, true},    // a full representation of a JIRA issue in JSON format
            {404, false}    // requested issue is not found, or the user does not have permission to view it
        };
        callback(statusCode, data, codes, QJSValueList{jsArg(issue)});
    });
}

