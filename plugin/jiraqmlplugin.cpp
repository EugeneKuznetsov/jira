#include <qqml.h>

#include "jiraqmlplugin.h"
#include "qmltypes/jira.h"
#include "qmltypes/options.h"
#include "qmltypes/resources/issue.h"

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Issue>(uri, 1, 0, "Issue");
    qmlRegisterType<Options>(uri, 1, 0, "Options");
    qmlRegisterType<Jira>(uri, 1, 0, "Jira");
}
