#include <qqml.h>

#include "jiraqmlplugin.h"
#include "qmltypes/jira.h"

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Jira>(uri, 1, 0, "Jira");
}
