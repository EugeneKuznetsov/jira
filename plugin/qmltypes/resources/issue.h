#pragma once

#include <QObject>
#include <QJsonDocument>

class Issue : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ getId)
    Q_PROPERTY(QString key READ getKey)

public:
    explicit Issue(QObject *parent = nullptr);
    Issue(const QJsonDocument &issueJson, QObject *parent = nullptr);

    const QString &getId() const;
    const QString &getKey() const;

private:
    QString m_id;
    QString m_key;
};
