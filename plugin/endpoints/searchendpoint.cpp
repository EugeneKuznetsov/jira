#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "searchendpoint.h"

SearchEndpoint::SearchEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : SearchEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *SearchEndpoint::onSearchUsingSearchRequestRequest()
{
    return SearchEndpointProxy::onSearchUsingSearchRequestRequest();
}
