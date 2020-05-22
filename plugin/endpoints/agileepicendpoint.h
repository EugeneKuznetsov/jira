#pragma once

#include "agileproxies/agileepicendpointproxy.h"

class AgileEpicEndpoint : public AgileEpicEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AgileEpicEndpoint)

public:
    AgileEpicEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onMoveIssuesToEpicRequest() override;
    virtual Reply *onPartiallyUpdateEpicRequest() override;
    virtual Reply *onRankEpicsRequest() override;
    virtual Reply *onRemoveIssuesFromEpicRequest() override;
};
