#pragma once

#include "endpoint.h"

class UserEndpoint : public Endpoint
{
    Q_DISABLE_COPY(UserEndpoint)

public:
    UserEndpoint(const QJSValue &jsCallback, Jira *parent);

    void getUserResource(const QString &username);

private:
    void getUser(const QUrlQuery &query);
};
