#include "projectcategoryendpoint.h"

ProjectCategoryEndpoint::ProjectCategoryEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ProjectCategoryEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}

Reply *ProjectCategoryEndpoint::onCreateProjectCategoryRequest()
{
    return ProjectCategoryEndpointProxy::onCreateProjectCategoryRequest();
}

Reply *ProjectCategoryEndpoint::onUpdateProjectCategoryRequest()
{
    return ProjectCategoryEndpointProxy::onUpdateProjectCategoryRequest();
}
