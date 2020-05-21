#include "filterendpoint.h"

FilterEndpoint::FilterEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : FilterEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *FilterEndpoint::onAddSharePermissionRequest()
{
    return FilterEndpointProxy::onAddSharePermissionRequest();
}

Reply *FilterEndpoint::onCreateFilterRequest()
{
    return FilterEndpointProxy::onCreateFilterRequest();
}

Reply *FilterEndpoint::onEditFilterRequest()
{
    return FilterEndpointProxy::onEditFilterRequest();
}

Reply *FilterEndpoint::onSetColumnsRequest()
{
    return FilterEndpointProxy::onSetColumnsRequest();
}

Reply *FilterEndpoint::onSetDefaultShareScopeRequest()
{
    return FilterEndpointProxy::onSetDefaultShareScopeRequest();
}
