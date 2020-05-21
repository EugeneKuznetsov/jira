#include "settingsendpoint.h"

SettingsEndpoint::SettingsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : SettingsEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *SettingsEndpoint::onSetBaseURLRequest()
{
    return SettingsEndpointProxy::onSetBaseURLRequest();
}

Reply *SettingsEndpoint::onSetIssueNavigatorDefaultColumnsRequest()
{
    return SettingsEndpointProxy::onSetIssueNavigatorDefaultColumnsRequest();
}
