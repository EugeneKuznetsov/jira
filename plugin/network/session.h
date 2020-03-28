#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

class Session : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Session)

    Session();

public:
    Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent);

    QNetworkReply *get(const QUrl &uri);

private:
    QNetworkAccessManager   *m_network;
    QUrl                    m_server;
};
