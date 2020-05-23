#pragma once

#include "proxies/searchendpointproxy.h"

class SearchEndpoint : public SearchEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(SearchEndpoint)

public:
    SearchEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onSearchUsingSearchRequestRequest() override;
};
