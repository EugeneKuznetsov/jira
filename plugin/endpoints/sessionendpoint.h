#pragma once

#include "endpoint.h"

class SessionEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(SessionEndpoint)

public:
    SessionEndpoint(const QJSValue &jsCallback, Jira *parent);

public slots:
    void login(const QString &username, const QString &password);
    void logout();
    void currentUser();
};
