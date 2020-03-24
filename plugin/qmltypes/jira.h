#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Connection connectionStatus READ getConnectionStatus NOTIFY connectionStatusChanged)

public:
    enum Connection {
        OFFLINE = 0,
        CONNECTING,
        ONLINE
    };
    Q_ENUM(Connection)

    explicit Jira(QObject *parent = nullptr);

    const Connection &getConnectionStatus() const {
        return m_connectionStatus;
    }

signals:
    void connectionStatusChanged();

public slots:
    void connect(const QUrl &server);

private:
    Session     *m_session;
    Connection  m_connectionStatus;
};
