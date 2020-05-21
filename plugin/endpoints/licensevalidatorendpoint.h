#pragma once

#include "proxies/licensevalidatorendpointproxy.h"

class LicenseValidatorEndpoint : public LicenseValidatorEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(LicenseValidatorEndpoint)

public:
    LicenseValidatorEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onValidateRequest() override;
};
