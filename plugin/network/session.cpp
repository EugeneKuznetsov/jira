#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "session.h"

Session::Session(const QUrl &server, QObject *parent)
    : QObject(parent)
    , m_network(new QNetworkAccessManager(this))
    , m_server(server)
{
}

QNetworkReply *Session::httpGet(QNetworkRequest *request)
{
    Q_UNUSED(request)

    return nullptr;
}
