#include <qqml.h>
#include "jira.h"
#include "jiraqmlplugin.h"

JiraQmlPlugin::JiraQmlPlugin(QObject *parent/* = nullptr*/)
    : QQmlExtensionPlugin(parent)
{
}

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Jira>(uri, 1, 1, "Jira");
}
