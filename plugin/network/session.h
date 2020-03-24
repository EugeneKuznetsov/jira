#pragma once

#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;

class Session : public QObject
{
    Q_OBJECT

public:
    Session(const QUrl &server, QObject *parent);

    QNetworkReply *httpGet(QNetworkRequest *request);

private:
    QNetworkAccessManager   *m_network;
    QUrl                    m_server;
};
