#pragma once

#include "endpoint.h"

class SearchEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(SearchEndpoint)

public:
    SearchEndpoint(const QJSValue &jsCallback, Jira *parent);

public slots:
    void search(const QString &jql, const int startAt = 0, const int maxResults = 50,
                const QString &fields = "*navigable", const QString &expand = "");
};
