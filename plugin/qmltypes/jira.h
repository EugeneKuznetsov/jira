#pragma once

#include <QObject>
#include <QJSValue>

#include "options.h"

class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Options *options READ getOptions WRITE setOptions NOTIFY optionsChanged)

public:
    explicit Jira(QObject *parent = nullptr);

    Options *getOptions() const;

    void setOptions(Options *new_value);

signals:
    void optionsChanged();
    void networkErrorDetails(const QString &errorString);

public slots:
    void login(const QJSValue &callback);
    void issue(const QString &issueIdOrKey, const QJSValue &callback);
    void search(const QString &jql, const QJSValue &callback, const int startAt = 0, const int maxResults = 50);

private:
    Session *activeSession(bool createNewSession = false);

private:
    Options *m_options;
    Session *m_session;
};
