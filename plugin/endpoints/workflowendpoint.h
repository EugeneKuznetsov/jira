#pragma once

#include "proxies/workflowendpointproxy.h"

class WorkflowEndpoint : public WorkflowEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(WorkflowEndpoint)

public:
    WorkflowEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
