#include "upgradeendpoint.h"

UpgradeEndpoint::UpgradeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : UpgradeEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *UpgradeEndpoint::onRunUpgradesNowRequest()
{
    return UpgradeEndpointProxy::onRunUpgradesNowRequest();
}
