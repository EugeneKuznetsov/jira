#pragma once

#include "proxies/worklogendpointproxy.h"

class WorklogEndpoint : public WorklogEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(WorklogEndpoint)

public:
    WorklogEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onGetWorklogsForIdsRequest() override;
};
