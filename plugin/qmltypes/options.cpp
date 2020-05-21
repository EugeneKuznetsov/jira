#include "options.h"
#include "utils/logging.h"

Options::Options(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_server()
{
    qCDebug(JIRA_INTERNAL) << "created:" << this;
}

const QUrl &Options::getServer() const
{
    return m_server;
}

void Options::setServer(const QUrl &newValue)
{
    qCDebug(JIRA_INTERNAL) << this << "new server:" << newValue;
    m_server = newValue;
    emit serverChanged(m_server);
}
