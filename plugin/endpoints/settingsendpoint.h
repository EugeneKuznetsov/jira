#pragma once

#include "proxies/settingsendpointproxy.h"

class SettingsEndpoint : public SettingsEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(SettingsEndpoint)

public:
    SettingsEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSetBaseURLRequest() override;
    virtual Reply *onSetIssueNavigatorDefaultColumnsRequest() override;
};
