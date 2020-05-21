#pragma once

#include "proxies/projectendpointproxy.h"

class ProjectEndpoint : public ProjectEndpointProxy
{
    Q_OBJECT
    Q_DISABLE_COPY(ProjectEndpoint)

public:
    ProjectEndpoint(const QJSValue &jsCallback, Session *parent, QJSEngine *jsEng, QQmlEngine *qmlEng);

protected:
    virtual Reply *onAddActorUsersRequest() override;
    virtual Reply *onArchiveProjectRequest() override;
    virtual Reply *onAssignPermissionSchemeRequest() override;
    virtual Reply *onAssignPrioritySchemeRequest() override;
    virtual Reply *onCreateAvatarFromTemporaryRequest() override;
    virtual Reply *onCreateProjectRequest() override;
    virtual Reply *onRestoreProjectRequest() override;
    virtual Reply *onSetActorsRequest() override;
    virtual Reply *onSetPropertyRequest() override;
    virtual Reply *onStoreTemporaryAvatarRequest() override;
    virtual Reply *onStoreTemporaryAvatarUsingMultiPartRequest() override;
    virtual Reply *onUpdateProjectRequest() override;
    virtual Reply *onUpdateProjectAvatarRequest() override;
    virtual Reply *onUpdateProjectTypeRequest() override;
};
