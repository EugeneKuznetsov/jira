#pragma once

#include "endpoint.h"

class SearchEndpoint : public Endpoint
{
    Q_OBJECT
    Q_DISABLE_COPY(SearchEndpoint)

public:
    SearchEndpoint(const QJSValue &jsCallback, Session *session, Jira *parent);

public slots:
    void search(const QString &jql, const int startAt, const int maxResults, const QString &fields, const QString &expand);

private:
    Session     *m_session;
    QJSValue    m_callback;
    const QUrl  m_baseUri;
};
