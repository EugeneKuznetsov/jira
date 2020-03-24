#include <QNetworkAccessManager>
#include "network/session.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_session(nullptr)
    , m_connectionStatus(OFFLINE)
{
}

void Jira::connect(const QUrl &server)
{
    if (nullptr != m_session)
        delete m_session;
    m_session = new Session(server, this);
    m_connectionStatus = CONNECTING;
    emit connectionStatusChanged();
}
