#include "applicationpropertiesendpoint.h"

ApplicationPropertiesEndpoint::ApplicationPropertiesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ApplicationPropertiesEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ApplicationPropertiesEndpoint::onSetPropertyViaRestfulTableRequest()
{
    return ApplicationPropertiesEndpointProxy::onSetPropertyViaRestfulTableRequest();
}
