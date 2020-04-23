#include <QNetworkReply>
#include "reply.h"
#include "utils/logging.h"

Reply::Reply(QNetworkReply *networkReply, QObject *parent)
    : QObject(parent)
    , m_networkReply(networkReply)
{
    if (nullptr == parent)
        qCCritical(NETWORK_REPLY) << "parent was not set for this Reply:" << this;
    if (nullptr == networkReply)
        qCCritical(NETWORK_REPLY) << "networkReply was not set for this Reply:" << this;
    connect(networkReply, &QNetworkReply::finished, this, &Reply::onReady);
}

void Reply::onReady()
{
    const qint32 statusCode = m_networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const QByteArray data = m_networkReply->readAll();

    qCDebug(NETWORK_REPLY) << this << "statusCode:" << statusCode << " data.size():" << data.size();

    if (0 == statusCode) {
        qCWarning(NETWORK_REPLY) << this << m_networkReply->errorString();
        emit networkError(m_networkReply->errorString());
    } else {
        qCDebug(NETWORK_REPLY_DATA) << this << data;
        emit ready(statusCode, data);
    }

    m_networkReply->deleteLater();
    emit destroy();
}
