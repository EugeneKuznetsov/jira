#pragma once

#include "proxies/issuetypeendpointproxy.h"

class IssueTypeEndpoint : public IssueTypeEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueTypeEndpoint)

public:
    IssueTypeEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateAvatarFromTemporaryRequest() override;
    virtual Reply *onCreateIssueTypeRequest() override;
    virtual Reply *onSetPropertyRequest() override;
    virtual Reply *onStoreTemporaryAvatarRequest() override;
    virtual Reply *onStoreTemporaryAvatarUsingMultiPartRequest() override;
    virtual Reply *onUpdateIssueTypeRequest() override;
};
