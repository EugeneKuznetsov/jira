#include <QJsonObject>
#include "issue.h"

Issue::Issue(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_id()
    , m_key()
    , m_self()
    , m_expandFlags()
{
}

Issue::Issue(const QJsonDocument &issueJson, QObject *parent/* = nullptr*/)
    : QObject(parent)
{
    QJsonObject root = issueJson.object();
    m_id = root["id"].toString();
    m_key = root["key"].toString();
    m_self = root["self"].toString();
    m_expandFlags = root["expand"].toString();
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
