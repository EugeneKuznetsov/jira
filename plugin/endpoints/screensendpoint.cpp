#include "screensendpoint.h"

ScreensEndpoint::ScreensEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ScreensEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ScreensEndpoint::onAddFieldRequest()
{
    return ScreensEndpointProxy::onAddFieldRequest();
}

Reply *ScreensEndpoint::onAddFieldToDefaultScreenRequest()
{
    return ScreensEndpointProxy::onAddFieldToDefaultScreenRequest();
}

Reply *ScreensEndpoint::onAddTabRequest()
{
    return ScreensEndpointProxy::onAddTabRequest();
}

Reply *ScreensEndpoint::onMoveFieldRequest()
{
    return ScreensEndpointProxy::onMoveFieldRequest();
}

Reply *ScreensEndpoint::onMoveTabRequest()
{
    return ScreensEndpointProxy::onMoveTabRequest();
}

Reply *ScreensEndpoint::onRenameTabRequest()
{
    return ScreensEndpointProxy::onRenameTabRequest();
}
