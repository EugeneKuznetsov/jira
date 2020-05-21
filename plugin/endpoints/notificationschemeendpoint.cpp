#include "notificationschemeendpoint.h"

NotificationSchemeEndpoint::NotificationSchemeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : NotificationSchemeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
