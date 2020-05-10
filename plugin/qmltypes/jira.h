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
    bool login(const QJSValue &callback);
    bool issue(const QJSValue &callback, const QString &issueIdOrKey,
               const QString &fields = "*all", const QString &expand = "");
    bool search(const QJSValue &callback, const QString &jql, const int startAt = 0, const int maxResults = 50,
                const QString &fields = "*navigable", const QString &expand = "");
    bool user(const QJSValue &callback, const QString &username);

private:
    friend class Endpoint;
    Session *activeSession(bool createNewSession = false);

private:
    Options *m_options;
    Session *m_session;
};
