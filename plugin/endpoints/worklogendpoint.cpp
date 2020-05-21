#include "worklogendpoint.h"

WorklogEndpoint::WorklogEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : WorklogEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *WorklogEndpoint::onGetWorklogsForIdsRequest()
{
    return WorklogEndpointProxy::onGetWorklogsForIdsRequest();
}
