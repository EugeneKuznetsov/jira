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
    else
        networkReply->setParent(this);

    // https://wiki.qt.io/New_Signal_Slot_Syntax#Overload
    void (QNetworkReply:: *errorSignal)(QNetworkReply::NetworkError) = &QNetworkReply::error;
    connect(networkReply, errorSignal, this, [this, networkReply](QNetworkReply::NetworkError) {
        // we are interested only in network layer and proxy errors
        // as of Qt 5.14, they are defined before ContentAccessDenied literal
        if (networkReply->error() < QNetworkReply::ContentAccessDenied) {
            qCWarning(NETWORK_REPLY) << this << networkReply->error() << networkReply->errorString();
            emit networkError(m_networkReply->errorString());
        }
    });
    connect(networkReply, &QNetworkReply::finished, this, &Reply::onReady);
}

void Reply::onReady()
{
    const qint32 statusCode = m_networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const QByteArray data = m_networkReply->readAll();

    qCDebug(NETWORK_REPLY) << this << "statusCode:" << statusCode << " data.size():" << data.size();

    if (0 != statusCode) {
        qCDebug(NETWORK_REPLY_DATA) << this << data;
        emit ready(statusCode, data);
    }

    emit destroy();
}
