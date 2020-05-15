#pragma once

#include <QObject>
#include <QUrl>

class Options : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Options)

    Q_PROPERTY(QUrl server READ getServer WRITE setServer NOTIFY serverChanged)

public:
    explicit Options(QObject *parent = nullptr);

    const QUrl &getServer() const;
    void setServer(const QUrl &newValue);

signals:
    void serverChanged(const QUrl &newValue);

private:
    QUrl m_server;
};
