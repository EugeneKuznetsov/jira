#include "workflowendpoint.h"

WorkflowEndpoint::WorkflowEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : WorkflowEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
