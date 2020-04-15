#include "user.h"
#include "logging.h"

User::User(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_self()
    , m_name()
    , m_displayName()
{   
}

User::User(const QJsonObject &userJson)
    : QObject(nullptr)
{
    m_self = userJson["self"].toString();
    m_name = userJson["name"].toString();
    m_displayName = userJson["displayName"].toString();
    qCDebug(RESOURCES) << "created:" << this;
    qCDebug(RESOURCES) << this << QJsonDocument(userJson).toJson(QJsonDocument::Indented);
}

const QUrl &User::getSelf() const
{
    return m_self;
}

const QString &User::getName() const
{
    return m_name;
}

const QString &User::getDisplayName() const
{
    return m_displayName;
}
