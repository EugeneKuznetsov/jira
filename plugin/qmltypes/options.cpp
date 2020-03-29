#include "options.h"

Options::Options(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_server("http://localhost:2990/jira")
    , m_username()
    , m_password()
{
}
