#pragma once

#include "proxies/projectvalidateendpointproxy.h"

class ProjectValidateEndpoint : public ProjectValidateEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ProjectValidateEndpoint)

public:
    ProjectValidateEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);
};
