#pragma once

#include "proxies/issuelinktypeendpointproxy.h"

class IssueLinkTypeEndpoint : public IssueLinkTypeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueLinkTypeEndpoint)

public:
    IssueLinkTypeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateIssueLinkTypeRequest() override;
    virtual Reply *onUpdateIssueLinkTypeRequest() override;
};
