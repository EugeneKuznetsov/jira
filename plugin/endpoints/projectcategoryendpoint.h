#pragma once

#include "proxies/projectcategoryendpointproxy.h"

class ProjectCategoryEndpoint : public ProjectCategoryEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ProjectCategoryEndpoint)

public:
    ProjectCategoryEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onCreateProjectCategoryRequest() override;
    virtual Reply *onUpdateProjectCategoryRequest() override;
};
