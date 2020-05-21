#pragma once

#include "proxies/mypreferencesendpointproxy.h"

class MyPreferencesEndpoint : public MyPreferencesEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(MyPreferencesEndpoint)

public:
    MyPreferencesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSetPreferenceRequest() override;
};
