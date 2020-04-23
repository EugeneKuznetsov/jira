#pragma once

#include <QObject>
#include "utils/globals.h"

class QNetworkReply;

class SHARED_SYMBOL Reply : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Reply)

    Reply();

public:
    Reply(QNetworkReply *networkReply, QObject *parent);

signals:
    void ready(const int statusCode, const QByteArray &data);
    void destroy();
    void networkError(const QString &errorString);

private slots:
    void onReady();

private:
    QNetworkReply   *m_networkReply;
};
