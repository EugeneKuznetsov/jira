#pragma once

#include <QQmlEngine>
#include <QObject>
#include <QJSValue>
#include "options.h"

class Session;
class SessionEndpoint;
class IssueEndpoint;

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
    QObject *session(QJSValue callback = QJSValue());
    QObject *issue(QJSValue callback = QJSValue());
    QObject *search(QJSValue callback = QJSValue());
    QObject *user(QJSValue callback = QJSValue());

private:
    template <typename EP>
    QObject *endpoint(QJSValue callback) {
        EP *ep = new EP(callback, this);
        qmlEngine(parent())->setObjectOwnership(ep, QQmlEngine::JavaScriptOwnership);
        return ep;
    }

private:
    friend class Endpoint;
    Session *activeSession(bool createNewSession = false);

private:
    Options *m_options;
    Session *m_session;
};
