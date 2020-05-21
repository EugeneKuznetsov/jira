#pragma once

#include "proxies/filterendpointproxy.h"

class FilterEndpoint : public FilterEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(FilterEndpoint)

public:
    FilterEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddSharePermissionRequest() override;
    virtual Reply *onCreateFilterRequest() override;
    virtual Reply *onEditFilterRequest() override;
    virtual Reply *onSetColumnsRequest() override;
    virtual Reply *onSetDefaultShareScopeRequest() override;
};
