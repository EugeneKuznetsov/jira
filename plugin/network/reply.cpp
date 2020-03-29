#include <QNetworkReply>
#include "reply.h"

Reply::Reply(QNetworkReply *networkReply, QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_networkReply(networkReply)
    , m_errorString()
{
    connect(networkReply, &QNetworkReply::finished, this, &Reply::onReady);
}

void Reply::onReady()
{
    const qint32 statusCode = m_networkReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    const QByteArray data = m_networkReply->readAll();

    if (0 == statusCode)
        m_errorString = m_networkReply->errorString();

    emit ready(statusCode, data);

    m_networkReply->deleteLater();
}
