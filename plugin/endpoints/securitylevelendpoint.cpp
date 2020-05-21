#include "securitylevelendpoint.h"

SecurityLevelEndpoint::SecurityLevelEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : SecurityLevelEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
