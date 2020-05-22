#include <qqml.h>
#include "qmltypes/issue.h"
#include "qmltypes/user.h"
#include "jira.h"
#include "jiraqmlplugin.h"

JiraQmlPlugin::JiraQmlPlugin(QObject *parent/* = nullptr*/)
    : QQmlExtensionPlugin(parent)
{
}

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Issue>(uri, 1, 1, "Issue");
    qmlRegisterUncreatableType<User>(uri, 1, 1, "User",
        "User type can only be returned via callback and cannot be instantiated separately");
    qmlRegisterType<Jira>(uri, 1, 1, "Jira");
}
