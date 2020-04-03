#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class Reply;

class Session : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Session)

    Q_PROPERTY(QUrl server MEMBER m_server WRITE setServer)

    Session();

public:
    Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent);

    Reply *get(const QUrl &uri);
    Reply *post(const QUrl &uri, const QByteArray &payload);

    void setServer(const QUrl &newValue) {
        m_server = newValue;
    }

private:
    QUrl completeUri(const QUrl &uri) const;

private:
    QNetworkAccessManager   *m_network;
    QUrl                    m_server;
};
