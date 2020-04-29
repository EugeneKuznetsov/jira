#include <QJsonObject>
#include "issue.h"
#include "utils/logging.h"

Issue::Issue(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_self()
    , m_id()
    , m_key()
    , m_expandFlags()
    , m_fields()
    , m_expandedFields()
{
    qCDebug(RESOURCES) << "created:" << this;
}

Issue::Issue(const QJsonObject &issueJson)
    : QObject(nullptr)
{
    m_self = issueJson["self"].toString();
    m_id = issueJson["id"].toString();
    m_key = issueJson["key"].toString();
    m_expandFlags = issueJson["expand"].toString();
    if (!issueJson.value("fields").isUndefined())
        m_fields = issueJson["fields"].toObject().toVariantMap();
    parseExpandedJson(issueJson);
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

unsigned char Issue::getExpandFlags() const
{
    quint8 flags = 0x00;
    flags |= (m_expandFlags.contains("renderedFields")) ? RenderedFields : 0;
    flags |= (m_expandFlags.contains("names")) ? Names : 0;
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

const QVariantMap &Issue::getExpandedFields() const
{
    return m_expandedFields;
}

void Issue::parseExpandedJson(const QJsonObject &issueJson)
{
    if (!issueJson.value("renderedFields").isUndefined())
        m_expandedFields.insert("renderedFields", issueJson["renderedFields"]);
    if (!issueJson.value("names").isUndefined())
        m_expandedFields.insert("names", issueJson["names"]);
    if (!issueJson.value("schema").isUndefined())
        m_expandedFields.insert("schema", issueJson["schema"]);
    if (!issueJson.value("operations").isUndefined())
        m_expandedFields.insert("operations", issueJson["operations"]);
    if (!issueJson.value("editmeta").isUndefined())
        m_expandedFields.insert("editmeta", issueJson["editmeta"]);
    if (!issueJson.value("changelog").isUndefined())
        m_expandedFields.insert("changelog", issueJson["changelog"]);
    if (!issueJson.value("versionedRepresentations").isUndefined())
        m_expandedFields.insert("versionedRepresentations", issueJson["versionedRepresentations"]);
}
