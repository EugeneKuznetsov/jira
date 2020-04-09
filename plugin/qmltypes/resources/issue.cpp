#include <QJsonObject>
#include "issue.h"
#include "logging.h"

Issue::Issue(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_self()
    , m_id()
    , m_key()
    , m_expandFlags()
    , m_fields()
{
    qCDebug(RESOURCES) << "created:" << this;
}

Issue::Issue(const QJsonDocument &issueJson, QObject *parent/* = nullptr*/)
    : QObject(parent)
{
    QJsonObject root = issueJson.object();
    m_self = root["self"].toString();
    m_id = root["id"].toString();
    m_key = root["key"].toString();
    m_expandFlags = root["expand"].toString();
    m_fields = root["fields"].toObject().toVariantMap();
    qCDebug(RESOURCES) << "created:" << this;
    qCDebug(RESOURCES) << this << issueJson.toJson(QJsonDocument::Indented);
}

Issue::Issue(const QJsonObject &issueJson, QObject *parent)
    : QObject(parent)
{
    m_self = issueJson["self"].toString();
    m_id = issueJson["id"].toString();
    m_key = issueJson["key"].toString();
    m_expandFlags = issueJson["expand"].toString();
    m_fields = issueJson["fields"].toObject().toVariantMap();
    qCDebug(RESOURCES) << "created:" << this;
    qCDebug(RESOURCES) << this << QJsonDocument(issueJson).toJson(QJsonDocument::Indented);
}

const QString &Issue::getId() const
{
    return m_id;
}

const QString &Issue::getKey() const
{
    return m_key;
}

const QUrl &Issue::getSelf() const
{
    return m_self;
}

quint8 Issue::getExpand() const
{
    quint8 flags = 0x00;
    flags |= (m_expandFlags.contains("renderedFields")) ? RenderedFields : 0;
    flags |= (m_expandFlags.contains("name")) ? Names : 0;
    flags |= (m_expandFlags.contains("schema")) ? Schema : 0;
    flags |= (m_expandFlags.contains("operations")) ? Operations : 0;
    flags |= (m_expandFlags.contains("editmeta")) ? EditMeta : 0;
    flags |= (m_expandFlags.contains("changelog")) ? Changelog : 0;
    flags |= (m_expandFlags.contains("versionedRepresentations")) ? VersionedRepresentations : 0;
    return flags;
}

const QVariantMap &Issue::getFields() const
{
    return m_fields;
}

void Issue::setFields(const QVariantMap &newValue)
{
    qCDebug(RESOURCES) << this << newValue;
    m_fields = newValue;
}
