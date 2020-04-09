#pragma once

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QUrl>

class Issue : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ getId)
    Q_PROPERTY(QString key READ getKey)
    Q_PROPERTY(QUrl self READ getSelf)
    Q_PROPERTY(quint8 expand READ getExpand)
    Q_PROPERTY(QVariantMap fields READ getFields WRITE setFields)

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
    Issue(const QJsonDocument &issueJson, QObject *parent = nullptr);
    Issue(const QJsonObject &issueJson, QObject *parent = nullptr);

    const QString &getId() const;
    const QString &getKey() const;
    const QUrl &getSelf() const;
    quint8 getExpand() const;
    const QVariantMap &getFields() const;

    void setFields(const QVariantMap &newValue);

signals:
    void onFieldsChanged();

private:
    QUrl        m_self;
    QString     m_id;
    QString     m_key;
    QString     m_expandFlags;
    QVariantMap m_fields;
};
