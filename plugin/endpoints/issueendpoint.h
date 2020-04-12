#pragma once

#include <QObject>
#include <QJSValue>
#include <QUrl>

class Session;
class Jira;

class IssueEndpoint : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(IssueEndpoint)

    IssueEndpoint();

public:
    IssueEndpoint(Session *session, const QJSValue &callback, Jira *parent);

public slots:
    void getIssue(const QString &issueIdOrKey);

private:
    Session     *m_session;
    QJSValue    m_callback;
    const QUrl  m_baseUri;
};
