#pragma once

#include "proxies/attachmentendpointproxy.h"

class AttachmentEndpoint : public AttachmentEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(AttachmentEndpoint)

public:
    AttachmentEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

};
