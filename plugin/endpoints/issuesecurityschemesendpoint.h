#pragma once

#include "proxies/issuesecurityschemesendpointproxy.h"

class IssueSecuritySchemesEndpoint : public IssueSecuritySchemesEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueSecuritySchemesEndpoint)

public:
    IssueSecuritySchemesEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

};
