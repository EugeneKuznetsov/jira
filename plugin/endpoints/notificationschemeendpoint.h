#pragma once

#include "proxies/notificationschemeendpointproxy.h"

class NotificationSchemeEndpoint : public NotificationSchemeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(NotificationSchemeEndpoint)

public:
    NotificationSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
