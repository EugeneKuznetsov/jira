#include "configurationendpoint.h"

ConfigurationEndpoint::ConfigurationEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ConfigurationEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
