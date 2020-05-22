#pragma once

#include "agileproxies/agilesprintendpointproxy.h"

class AgileSprintEndpoint : public AgileSprintEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AgileSprintEndpoint)

public:
    AgileSprintEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateSprintRequest() override;
    virtual Reply *onMoveIssuesToSprintRequest() override;
    virtual Reply *onPartiallyUpdateSprintRequest() override;
    virtual Reply *onSetPropertyRequest() override;
    virtual Reply *onSwapSprintRequest() override;
    virtual Reply *onUpdateSprintRequest() override;
};
