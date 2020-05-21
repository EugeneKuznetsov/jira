#include "issuelinktypeendpoint.h"

IssueLinkTypeEndpoint::IssueLinkTypeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : IssueLinkTypeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *IssueLinkTypeEndpoint::onCreateIssueLinkTypeRequest()
{
    return IssueLinkTypeEndpointProxy::onCreateIssueLinkTypeRequest();
}

Reply *IssueLinkTypeEndpoint::onUpdateIssueLinkTypeRequest()
{
    return IssueLinkTypeEndpointProxy::onUpdateIssueLinkTypeRequest();
}
