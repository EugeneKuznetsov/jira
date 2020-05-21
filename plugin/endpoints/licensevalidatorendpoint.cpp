#include "licensevalidatorendpoint.h"

LicenseValidatorEndpoint::LicenseValidatorEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : LicenseValidatorEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *LicenseValidatorEndpoint::onValidateRequest()
{
    return LicenseValidatorEndpointProxy::onValidateRequest();
}
