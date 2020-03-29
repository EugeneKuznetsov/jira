#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class Reply;

class Session : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Session)

    Session();

public:
    Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent);

    Reply *get(const QUrl &uri);

private:
    QUrl completeUri(const QUrl &uri) const;

private:
    QNetworkAccessManager   *m_network;
    QUrl                    m_server;
};
