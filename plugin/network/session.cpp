#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "reply.h"
#include "session.h"
#include "utils/logging.h"

Session::Session(const QUrl &server, QNetworkAccessManager *network, QObject *parent)
    : QObject(parent)
    , m_network(network)
    , m_server(server)
{
    if (nullptr == parent)
        qCWarning(NETWORK_SESSION) << "parent was not set";
    if (nullptr == network)
        qCCritical(NETWORK_SESSION) << "network was not set";
    qCDebug(NETWORK_SESSION) << this << "new session server address:" << server;
}

Reply *Session::get(const QUrl &uri)
{
    if (nullptr == m_network) {
        qCCritical(NETWORK_SESSION) << "network was not set";
        return nullptr;
    }
    qDebug(NETWORK_SESSION) << "uri:" << uri;

    QNetworkRequest request(completeUri(uri));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");

    Reply *reply = new Reply(m_network->get(request), this);
    qDebug(NETWORK_SESSION) << "created a new:" << reply;
    return reply;
}

Reply *Session::post(const QUrl &uri, const QByteArray &payload)
{
    if (nullptr == m_network) {
        qCCritical(NETWORK_SESSION) << "network was not set";
        return nullptr;
    }
    qDebug(NETWORK_SESSION) << "uri:" << uri;
    qDebug(NETWORK_SESSION_DATA) << "payload:" << payload;

    QNetworkRequest request(completeUri(uri));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");

    Reply *reply = new Reply(m_network->post(request, payload), this);
    qDebug(NETWORK_SESSION) << "created a new:" << reply;
    return reply;
}

const QUrl &Session::getServer() const
{
    return m_server;
}

void Session::setServer(const QUrl &newValue)
{
    qCDebug(NETWORK_SESSION) << this << "new server address:" << newValue;
    m_server = newValue;
    emit serverChanged(m_server);
}

QUrl Session::completeUri(const QUrl &uri) const
{
    return QUrl(m_server.toString() + uri.toString());
}
