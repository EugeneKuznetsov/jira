#include "projectendpoint.h"

ProjectEndpoint::ProjectEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng)
    : ProjectEndpointProxy(jsCallback, parent, jsEng, qmlEng)
{
}


Reply *ProjectEndpoint::onAddActorUsersRequest()
{
    return ProjectEndpointProxy::onAddActorUsersRequest();
}

Reply *ProjectEndpoint::onArchiveProjectRequest()
{
    return ProjectEndpointProxy::onArchiveProjectRequest();
}

Reply *ProjectEndpoint::onAssignPermissionSchemeRequest()
{
    return ProjectEndpointProxy::onAssignPermissionSchemeRequest();
}

Reply *ProjectEndpoint::onAssignPrioritySchemeRequest()
{
    return ProjectEndpointProxy::onAssignPrioritySchemeRequest();
}

Reply *ProjectEndpoint::onCreateAvatarFromTemporaryRequest()
{
    return ProjectEndpointProxy::onCreateAvatarFromTemporaryRequest();
}

Reply *ProjectEndpoint::onCreateProjectRequest()
{
    return ProjectEndpointProxy::onCreateProjectRequest();
}

Reply *ProjectEndpoint::onRestoreProjectRequest()
{
    return ProjectEndpointProxy::onRestoreProjectRequest();
}

Reply *ProjectEndpoint::onSetActorsRequest()
{
    return ProjectEndpointProxy::onSetActorsRequest();
}

Reply *ProjectEndpoint::onSetPropertyRequest()
{
    return ProjectEndpointProxy::onSetPropertyRequest();
}

Reply *ProjectEndpoint::onStoreTemporaryAvatarRequest()
{
    return ProjectEndpointProxy::onStoreTemporaryAvatarRequest();
}

Reply *ProjectEndpoint::onStoreTemporaryAvatarUsingMultiPartRequest()
{
    return ProjectEndpointProxy::onStoreTemporaryAvatarUsingMultiPartRequest();
}

Reply *ProjectEndpoint::onUpdateProjectRequest()
{
    return ProjectEndpointProxy::onUpdateProjectRequest();
}

Reply *ProjectEndpoint::onUpdateProjectAvatarRequest()
{
    return ProjectEndpointProxy::onUpdateProjectAvatarRequest();
}

Reply *ProjectEndpoint::onUpdateProjectTypeRequest()
{
    return ProjectEndpointProxy::onUpdateProjectTypeRequest();
}
