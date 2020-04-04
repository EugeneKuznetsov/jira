#include "issue.h"

Issue::Issue(QObject *parent/* = nullptr*/)
    : QObject(parent)
{
}

Issue::Issue(const QJsonDocument &issueJson, QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_id()
    , m_key()
{
    Q_UNUSED(issueJson);
}

const QString &Issue::getId() const
{
    return m_id;
}

const QString &Issue::getKey() const
{
    return m_key;
}
