#pragma once

#include "proxies/priorityschemesendpointproxy.h"

class PrioritySchemesEndpoint : public PrioritySchemesEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(PrioritySchemesEndpoint)

public:
    PrioritySchemesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreatePrioritySchemeRequest() override;
    virtual Reply *onUpdatePrioritySchemeRequest() override;
};
