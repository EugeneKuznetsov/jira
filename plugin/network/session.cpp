#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "session.h"

Session::Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent)
    : QObject(parent)
    , m_network(network)
    , m_server(server)
{
}

QNetworkReply *Session::get(const QUrl &uri)
{
    Q_UNUSED(uri)
    return nullptr;
}
