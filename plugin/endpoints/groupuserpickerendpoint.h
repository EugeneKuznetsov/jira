#pragma once

#include "proxies/groupuserpickerendpointproxy.h"

class GroupUserPickerEndpoint : public GroupUserPickerEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(GroupUserPickerEndpoint)

public:
    GroupUserPickerEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
