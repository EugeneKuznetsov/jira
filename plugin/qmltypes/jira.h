#pragma once

#include <QObject>
#include <QUrl>

#include "options.h"

class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Connection connectionStatus READ getConnectionStatus NOTIFY connectionStatusChanged)
    Q_PROPERTY(Options *options MEMBER m_options NOTIFY optionsChanged)

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
    void optionsChanged();

public slots:
    void connect();

private:
    Session     *m_session;
    Options     *m_options;
    Connection  m_connectionStatus;
};
