#include <qqml.h>

#include "jiraqmlplugin.h"
#include "jira.h"
#include "qmltypes/issue.h"
#include "qmltypes/user.h"


JiraQmlPlugin::JiraQmlPlugin(QObject *parent/* = nullptr*/)
    : QQmlExtensionPlugin(parent)
{
}

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Issue>(uri, 1, 0, "Issue");
    qmlRegisterUncreatableType<User>(uri, 1, 0, "User",
        "User type can only be returned via callback and cannot be instantiated separately");
    qmlRegisterType<Jira>(uri, 1, 0, "Jira");
}
