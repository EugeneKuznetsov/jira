#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "reply.h"
#include "session.h"

Session::Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent)
    : QObject(parent)
    , m_network(network)
    , m_server(server)
{
}

Reply *Session::get(const QUrl &uri)
{
    QNetworkRequest request(completeUri(uri));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");
    return new Reply(m_network->get(request), this);
}

QUrl Session::completeUri(const QUrl &uri) const
{
    return QUrl(m_server.toString() + uri.toString());
}
