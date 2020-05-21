#include "commentendpoint.h"

CommentEndpoint::CommentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : CommentEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *CommentEndpoint::onSetPropertyRequest()
{
    return CommentEndpointProxy::onSetPropertyRequest();
}
