#include "network/session.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_session(nullptr)
    , m_options(nullptr)
    , m_connectionStatus(OFFLINE)
{
}

void Jira::connect()
{
    m_connectionStatus = CONNECTING;
    emit connectionStatusChanged();
}
