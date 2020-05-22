#pragma once

#include "agileproxies/agileboardendpointproxy.h"

class AgileBoardEndpoint : public AgileBoardEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AgileBoardEndpoint)

public:
    AgileBoardEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateBoardRequest() override;
    virtual Reply *onSetPropertyRequest() override;
};
