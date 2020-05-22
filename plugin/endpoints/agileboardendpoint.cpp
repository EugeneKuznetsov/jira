#include "agileboardendpoint.h"

AgileBoardEndpoint::AgileBoardEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AgileBoardEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *AgileBoardEndpoint::onCreateBoardRequest()
{
    return AgileBoardEndpointProxy::onCreateBoardRequest();
}

Reply *AgileBoardEndpoint::onSetPropertyRequest()
{
    return AgileBoardEndpointProxy::onSetPropertyRequest();
}
