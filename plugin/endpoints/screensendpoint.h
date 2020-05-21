#pragma once

#include "proxies/screensendpointproxy.h"

class ScreensEndpoint : public ScreensEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ScreensEndpoint)

public:
    ScreensEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddFieldRequest() override;
    virtual Reply *onAddFieldToDefaultScreenRequest() override;
    virtual Reply *onAddTabRequest() override;
    virtual Reply *onMoveFieldRequest() override;
    virtual Reply *onMoveTabRequest() override;
    virtual Reply *onRenameTabRequest() override;
};
