#pragma once

#include "endpoint.h"

class UserEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(UserEndpoint)

public:
    UserEndpoint(const QJSValue &jsCallback, Jira *parent);

public slots:
    void getUser(const QString &username);
};
