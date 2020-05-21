#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "issue.h"
#include "searchendpoint.h"

SearchEndpoint::SearchEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : SearchEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *SearchEndpoint::onSearchUsingSearchRequestRequest()
{
    return SearchEndpointProxy::onSearchUsingSearchRequestRequest();
}

QJSValueList SearchEndpoint::onSearchSuccess(const QByteArray &data)
{
    QJSValueList resultIssues;
    const QJsonDocument json = QJsonDocument::fromJson(data);
    const QJsonObject &root = json.object();
    const QJsonArray &issues = root["issues"].toArray();
    const int total = root["total"].toInt();
    for (auto issue : issues)
        resultIssues.push_back(jsArg(new Issue(issue.toObject())));
    return QJSValueList{jsArg(resultIssues), jsArg(total)};
}

QJSValueList SearchEndpoint::onSearchError(const QByteArray &)
{
    return QJSValueList {jsArg(QJSValueList{}), jsArg(0)};
}
