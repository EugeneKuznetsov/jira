#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrlQuery>
#include "issueendpoint.h"
#include "utils/logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/jira.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/external/issue.h"

IssueEndpoint::IssueEndpoint(Session *session, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_session(session)
    , m_callback(callback)
    , m_baseUri("/rest/api/2/issue")
{
    qCDebug(JIRA_INTERNAL) << "created new endpoint:" << this << "with session:" << session;
    if (!callback.isCallable())
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
}

void IssueEndpoint::getIssue(const QString &issueIdOrKey, const QString &fields, const QString &expand)
{
    qCDebug(JIRA_API) << this << "issue or key:" << issueIdOrKey << "fields:" << fields << "expand:" << expand;

    QUrl path(m_baseUri.toString() + "/" + issueIdOrKey);
    path.setQuery(QUrlQuery({{"fields", fields}, {"expand", expand}}));
    Reply *reply = m_session->get(QUrl(path));
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying later:" << reply;
        reply->deleteLater();
        qCDebug(JIRA_API) << this << "self-destruction later:" << this;
        this->deleteLater();
    });
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, reply](const int statusCode, const QByteArray &data) {
        Issue *issue = nullptr;
        if (200 == statusCode) {
            qCDebug(JIRA_API_DATA) << this << reply << "successfuly received requested Issue";
            issue = new Issue(QJsonDocument::fromJson(data).object());
            qmlEngine(parent())->setObjectOwnership(issue, QQmlEngine::JavaScriptOwnership);
            qCDebug(JIRA_API_DATA) << this << reply << "created new:" << issue;
        }
        const StatusMap codes = {
            {200, true},    // a full representation of a JIRA issue in JSON format
            {404, false}    // requested issue is not found, or the user does not have permission to view it
        };
        ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
        qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        m_callback.call(QJSValueList{qjsEngine(parent())->toScriptValue(status), qjsEngine(parent())->toScriptValue(issue)});
    });
}

