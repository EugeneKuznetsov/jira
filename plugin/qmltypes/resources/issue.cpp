#include <QJsonObject>
#include "issue.h"

Issue::Issue(QObject *parent/* = nullptr*/)
    : QObject(parent)
{
}

Issue::Issue(const QJsonDocument &issueJson, QObject *parent/* = nullptr*/)
    : QObject(parent)
{
    QJsonObject root = issueJson.object();
    m_id = root["id"].toString();
    m_key = root["key"].toString();
}

const QString &Issue::getId() const
{
    return m_id;
}

const QString &Issue::getKey() const
{
    return m_key;
}
