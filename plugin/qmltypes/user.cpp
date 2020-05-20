#include "user.h"

User::User(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_self()
    , m_name()
    , m_displayName()
    , m_avatarUrls()
{   
}

User::User(const QJsonObject &userJson)
    : QObject(nullptr)
{
    m_self = userJson["self"].toString();
    m_name = userJson["name"].toString();
    m_displayName = userJson["displayName"].toString();
    m_avatarUrls = userJson["avatarUrls"].toVariant().toMap();
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

const QVariantMap &User::getAvatarUrls() const
{
    return m_avatarUrls;
}
