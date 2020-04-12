#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "searchendpoint.h"
#include "logging.h"
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/responsestatus.h"
#include "qmltypes/jira.h"
#include "qmltypes/resources/issue.h"

SearchEndpoint::SearchEndpoint(Session *session, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_session(session)
    , m_callback(callback)
    , m_baseUri("/rest/api/2/search")
{
    qCDebug(JIRA_INTERNAL) << "created new endpoint:" << this << "with session:" << session;
    if (!callback.isCallable())
        qCWarning(JIRA_INTERNAL) << this << "callback is not callable";
}

void SearchEndpoint::search(const QString &jql, const int startAt/* = 0*/, const int maxResults/* = 50*/)
{
    qCDebug(JIRA_API) << this << "jql:" << jql << "startAt:" << startAt << "maxResults:" << maxResults;

    QJsonObject root;
    root.insert("jql", jql);
    root.insert("startAt", startAt);
    root.insert("maxResults", maxResults);
    QJsonDocument payload(root);

    Reply *reply = m_session->post(m_baseUri, payload.toJson());
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying later:" << reply;
        reply->deleteLater();
        qCDebug(JIRA_API) << this << "self-destruction later:" << this;
        this->deleteLater();
    });
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, reply](const int statusCode, const QByteArray &data) {
        QJSValueList resultIssues;
        int total = 0;
        if (200 == statusCode) {
            qCDebug(JIRA_API_DATA) << this << reply << "successfuly received list of Issues";
            const QJsonDocument json = QJsonDocument::fromJson(data);
            const QJsonObject &root = json.object();
            const QJsonArray &issues = root["issues"].toArray();
            total = root["total"].toInt();
            for (auto issue : issues)
                resultIssues.push_back(qjsEngine(parent())->toScriptValue(new Issue(issue.toObject())));
        }
        const StatusMap codes = {
            {200, true},    // a JSON representation of the search results
            {400, false}    // there is a problem with the JQL query
        };
        ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
        qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        m_callback.call(QJSValueList{
                              qjsEngine(parent())->toScriptValue(status),
                              qjsEngine(parent())->toScriptValue(resultIssues),
                              qjsEngine(parent())->toScriptValue(total)
                          });
    });
}
