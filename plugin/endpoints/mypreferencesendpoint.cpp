#include "mypreferencesendpoint.h"

MyPreferencesEndpoint::MyPreferencesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : MyPreferencesEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *MyPreferencesEndpoint::onSetPreferenceRequest()
{
    return MyPreferencesEndpointProxy::onSetPreferenceRequest();
}
