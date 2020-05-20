#pragma once

#include <QQmlEngine>
#include <QObject>
#include <QJSValue>

class Session;
class SessionEndpoint;

class Jira : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl server READ getServer WRITE setServer NOTIFY serverChanged)

public:
    explicit Jira(QObject *parent = nullptr);

    const QUrl &getServer() const;
    void setServer(const QUrl &server);

signals:
    void networkErrorDetails(const QString &errorString);
    void serverChanged();

public slots:
    QObject *session(QJSValue callback = QJSValue());
    QObject *issue(QJSValue callback = QJSValue());
    QObject *search(QJSValue callback = QJSValue());
    QObject *user(QJSValue callback = QJSValue());

private:
    template <typename EP>
    QObject *endpoint(QJSValue callback) {
        EP *ep = new EP(callback, m_session, qjsEngine(this), qmlEngine(this));
        qmlEngine(parent())->setObjectOwnership(ep, QQmlEngine::JavaScriptOwnership);
        return ep;
    }

    Session *newSession(const QUrl &server);

private:
    Session *m_session;
};
