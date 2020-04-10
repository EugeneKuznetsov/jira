#pragma once

#include <QObject>
#include <QUrl>

class Options : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Options)

    Q_PROPERTY(QUrl server READ getServer WRITE setServer NOTIFY serverChanged)
    Q_PROPERTY(QString username MEMBER m_username NOTIFY usernameChanged)
    Q_PROPERTY(QString password MEMBER m_password NOTIFY passwordChanged)

public:
    explicit Options(QObject *parent = nullptr);

    const QUrl &getServer() const;
    void setServer(const QUrl &newValue);

signals:
    void serverChanged(const QUrl &newValue);
    void usernameChanged();
    void passwordChanged();

private:
    QUrl    m_server;
    QString m_username;
    QString m_password;
};
