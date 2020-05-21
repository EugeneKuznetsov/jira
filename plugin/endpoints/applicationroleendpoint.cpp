#include "applicationroleendpoint.h"

ApplicationRoleEndpoint::ApplicationRoleEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ApplicationRoleEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ApplicationRoleEndpoint::onPutRequest()
{
    return ApplicationRoleEndpointProxy::onPutRequest();
}

Reply *ApplicationRoleEndpoint::onPutBulkRequest()
{
    return ApplicationRoleEndpointProxy::onPutBulkRequest();
}
