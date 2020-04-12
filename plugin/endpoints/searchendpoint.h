#pragma once

#include <QObject>
#include <QJSValue>
#include <QUrl>

class Session;
class Jira;

class SearchEndpoint : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(SearchEndpoint)

    SearchEndpoint();

public:
    SearchEndpoint(Session *session, const QJSValue &callback, Jira *parent);

public slots:
    void search(const QString &jql, const int startAt = 0, const int maxResults = 50);

private:
    Session     *m_session;
    QJSValue    m_callback;
    const QUrl  m_baseUri;
};
