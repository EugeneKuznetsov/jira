#pragma once

#include "proxies/issuelinkendpointproxy.h"

class IssueLinkEndpoint : public IssueLinkEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueLinkEndpoint)

public:
    IssueLinkEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onLinkIssuesRequest() override;
};
