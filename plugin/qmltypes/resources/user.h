#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QUrl>
#include "globals.h"

class SHARED_SYMBOL User : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QUrl self READ getSelf)
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QString displayName READ getDisplayName)

public:
    explicit User(QObject *parent = nullptr);
    User(const QJsonObject &userJson);

    const QUrl &getSelf() const;
    const QString &getName() const;
    const QString &getDisplayName() const;

private:
    QUrl    m_self;
    QString m_name;
    QString m_displayName;
};
