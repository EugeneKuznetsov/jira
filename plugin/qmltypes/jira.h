#pragma once

#include <QObject>
#include <QJSValue>

#include "options.h"

class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Options *options READ getOptions WRITE setOptions NOTIFY optionsChanged)
    Q_PROPERTY(QString lastError READ getLastError NOTIFY lastErrorChanged)

public:
    explicit Jira(QObject *parent = nullptr);

    Options *getOptions() const {
        return m_options;
    }

    void setOptions(Options *new_value);
    const QString getLastError() const;

signals:
    void optionsChanged();
    void lastErrorChanged(const QString &errorString);

public slots:
    void login(const QJSValue &callback);

private:
    Session *activeSession(bool createNewSession = false);

private:
    Options *m_options;
    Session *m_session;
    QString m_lastNetworkError;
    QString m_lastJiraError;
};
