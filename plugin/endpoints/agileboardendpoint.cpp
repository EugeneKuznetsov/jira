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


void AgileBoardEndpoint::getAllBoards(const long long startAt/* = 0*/, const int maxResults/* = 50*/, const QString &type/* = ""*/,
                                      const QString &name/* = ""*/, const QString &projectKeyOrId/* = ""*/)
{
    AgileBoardEndpointProxy::getAllBoards(startAt, maxResults, type, name, projectKeyOrId);
}
