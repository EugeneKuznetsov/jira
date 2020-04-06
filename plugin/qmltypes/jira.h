#pragma once

#include <QObject>
#include <QJSValue>

#include "options.h"

#include "resources/issue.h"

class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Options *options READ getOptions WRITE setOptions NOTIFY optionsChanged)
    Q_PROPERTY(QString lastError READ getLastError NOTIFY lastErrorChanged)

public:
    enum ErrorTypes {
        NO_ERROR = 0,
        NETWORK_ERROR,
        JIRA_USER_ERROR,
        JIRA_API_ERROR
    };
    Q_ENUM(ErrorTypes)

public:
    explicit Jira(QObject *parent = nullptr);

    Options *getOptions() const;
    const QString getLastError() const;

    void setOptions(Options *new_value);

signals:
    void optionsChanged();
    void lastErrorChanged(const QString &errorString);

public slots:
    void login(const QJSValue &callback);
    void issue(const QString &issueIdOrKey, const QJSValue &callback);

    ErrorTypes getCurrentErrorType() const;

private:
    Session *activeSession(bool createNewSession = false);

private:
    Options     *m_options;
    Session     *m_session;
    QString     m_lastNetworkError;
    QString     m_lastJiraApiError;
    QString     m_lastJiraUserError;
    ErrorTypes  m_currentErrorType;
};
