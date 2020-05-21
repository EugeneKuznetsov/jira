#include "attachmentendpoint.h"

AttachmentEndpoint::AttachmentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : AttachmentEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}
