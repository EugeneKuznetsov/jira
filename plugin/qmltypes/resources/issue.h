#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QUrl>
#include "globals.h"

class SHARED_SYMBOL Issue : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ getId)
    Q_PROPERTY(QString key READ getKey)
    Q_PROPERTY(QUrl self READ getSelf)
    Q_PROPERTY(quint8 expandFlags READ getExpandFlags)
    Q_PROPERTY(QVariantMap fields READ getFields)
    Q_PROPERTY(QVariantMap expandedFields READ getExpandedFields)

public:
    enum ExpandFlag {
        RenderedFields = 0x01,
        Names = 0x02,
        Schema = 0x04,
        Operations = 0x08,
        EditMeta = 0x10,
        Changelog = 0x20,
        VersionedRepresentations = 0x40
    };
    Q_DECLARE_FLAGS(ExpandFlags, ExpandFlag)
    Q_FLAG(ExpandFlag)

public:
    explicit Issue(QObject *parent = nullptr);
    Issue(const QJsonObject &issueJson);

    const QString &getId() const;
    const QString &getKey() const;
    const QUrl &getSelf() const;
    unsigned char getExpandFlags() const;
    const QVariantMap &getFields() const;
    const QVariantMap &getExpandedFields() const;

private:
    void parseExpandedJson(const QJsonObject &issueJson);

private:
    QUrl        m_self;
    QString     m_id;
    QString     m_key;
    QString     m_expandFlags;
    QVariantMap m_fields;
    QVariantMap m_expandedFields;
};
