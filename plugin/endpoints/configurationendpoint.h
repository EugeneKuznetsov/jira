#pragma once

#include "proxies/configurationendpointproxy.h"

class ConfigurationEndpoint : public ConfigurationEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ConfigurationEndpoint)

public:
    ConfigurationEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
