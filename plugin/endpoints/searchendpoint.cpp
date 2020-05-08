#include <QJsonArray>
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/external/issue.h"
#include "qmltypes/jira.h"
#include "searchendpoint.h"

SearchEndpoint::SearchEndpoint(const QJSValue &jsCallback, Session *session, Jira *parent)
    : Endpoint(QUrl("/rest/api/2/search"), jsCallback, session, parent)
{
}

void SearchEndpoint::search(const QString &jql, const int startAt, const int maxResults,
                            const QString &fields, const QString &expand)
{
    QJsonArray fieldsArray;
    for (auto field : fields.split(","))
        fieldsArray.push_back(field);
    QJsonArray expandArray;
    for (auto expandField : expand.split(","))
        expandArray.push_back(expandField);
    QJsonDocument payload({{"jql", jql}, {"startAt", startAt}, {"maxResults", maxResults},
                           {"fields", fieldsArray}, {"expand", expandArray}});
    connect(post(payload.toJson()), &Reply::ready, [this](const int statusCode, const QByteArray &data) {
        QJSValueList resultIssues;
        int total = 0;
        if (200 == statusCode) {
            const QJsonDocument json = QJsonDocument::fromJson(data);
            const QJsonObject &root = json.object();
            const QJsonArray &issues = root["issues"].toArray();
            total = root["total"].toInt();
            for (auto issue : issues)
                resultIssues.push_back(jsArg(new Issue(issue.toObject())));
        }
        const StatusMap codes = {
            {200, true},    // a JSON representation of the search results
            {400, false}    // there is a problem with the JQL query
        };
        callback(statusCode, data, codes, QJSValueList {jsArg(resultIssues), jsArg(total)});
    });
}
