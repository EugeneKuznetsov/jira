#pragma once

#include "endpoint.h"

class UserEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(UserEndpoint)

public:
    UserEndpoint(const QJSValue &jsCallback, Session *session, Jira *parent);

    void getUserResource(const QString &username);

private:
    void getUser(const QUrlQuery &query);
};
