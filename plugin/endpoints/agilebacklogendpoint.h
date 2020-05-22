#pragma once

#include "agileproxies/agilebacklogendpointproxy.h"

class AgileBacklogEndpoint : public AgileBacklogEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AgileBacklogEndpoint)

public:
    AgileBacklogEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onMoveIssuesToBacklogRequest() override;
};
