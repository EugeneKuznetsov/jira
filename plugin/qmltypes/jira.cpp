#include "network/session.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_session(nullptr)
    , m_options(new Options(this))
{
}

void Jira::setOptions(Options *new_value)
{
    if (nullptr == new_value)
        return;
    if (nullptr != m_options)
        delete m_options;
    m_options = new_value;
    m_options->setParent(this);
}
