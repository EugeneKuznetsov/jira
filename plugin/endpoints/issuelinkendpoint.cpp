#include "issuelinkendpoint.h"

IssueLinkEndpoint::IssueLinkEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueLinkEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *IssueLinkEndpoint::onLinkIssuesRequest()
{
    return IssueLinkEndpointProxy::onLinkIssuesRequest();
}
