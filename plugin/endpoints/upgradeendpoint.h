#pragma once

#include "proxies/upgradeendpointproxy.h"

class UpgradeEndpoint : public UpgradeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(UpgradeEndpoint)

public:
    UpgradeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onRunUpgradesNowRequest() override;
};
