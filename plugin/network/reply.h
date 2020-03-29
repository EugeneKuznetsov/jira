#pragma once

#include <QObject>

class QNetworkReply;

class Reply : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Reply)

    Reply();

public:
    explicit Reply(QNetworkReply *networkReply, QObject *parent = nullptr);

    const QString &getErrorString() const {
        return m_errorString;
    }

signals:
    void ready(const int statusCode, const QByteArray &data);

private slots:
    void onReady();

private:
    QNetworkReply   *m_networkReply;
    QString         m_errorString;
};
