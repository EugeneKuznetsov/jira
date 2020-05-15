#include <qqml.h>

#include "jiraqmlplugin.h"
#include "utils/logging.h"
#include "qmltypes/jira.h"
#include "qmltypes/options.h"
#include "qmltypes/internal/responsestatus.h"
#include "qmltypes/external/issue.h"
#include "qmltypes/external/user.h"
#include "endpoints/sessionendpoint.h"
#include "endpoints/issueendpoint.h"
#include "endpoints/searchendpoint.h"
#include "endpoints/userendpoint.h"


JiraQmlPlugin::JiraQmlPlugin(QObject *parent/* = nullptr*/)
    : QQmlExtensionPlugin(parent)
{
    QPair<QString, QString> color_red("\033[31;1m", "\033[0;0m");
    QPair<QString, QString> color_green("\033[32;1m", "\033[0;0m");
    QPair<QString, QString> color_yellow("\033[33;1m", "\033[0;0m");
    QPair<QString, QString> color_white("\033[37;1m", "\033[0;0m");
    QString pattern = "[%{if-debug}D%{endif}"
                      "%{if-info}I%{endif}"
                      "%{if-warning}W%{endif}"
                      "%{if-critical}C%{endif}"
                      "%{if-fatal}F%{endif}] "
                      "[%{time h:mm:ss.zzz} | "
                      "%{category} | "
                      "%{function}:%{line}]   ";
    pattern = "%{if-debug}" + color_green.first + "%{endif}" + pattern + "%{if-debug}" + color_green.second + "%{endif}";
    pattern = "%{if-warning}" + color_yellow.first + "%{endif}" + pattern + "%{if-warning}" + color_yellow.second + "%{endif}";
    pattern = "%{if-critical}" + color_red.first + "%{endif}" + pattern + "%{if-critical}" + color_red.second + "%{endif}";
    pattern = "%{if-fatal}" + color_red.first + "%{endif}" + pattern + "%{if-fatal}" + color_red.second + "%{endif}";
    QString message = color_white.first + "%{message}" + color_white.second;
    qSetMessagePattern(pattern + message);
}

void JiraQmlPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Jira"));
    qmlRegisterType<Issue>(uri, 1, 0, "Issue");
    qmlRegisterUncreatableType<ResponseStatus>(uri, 1, 0, "ResponseStatus",
        "ResposeStatus is specific for Jira calls only and cannot be created separately");
    qmlRegisterUncreatableType<User>(uri, 1, 0, "User",
        "User type can only be returned via callback and cannot be instantiated separately");
    qmlRegisterType<Options>(uri, 1, 0, "Options");
    qmlRegisterType<Jira>(uri, 1, 0, "Jira");
    qmlRegisterUncreatableType<SessionEndpoint>(uri, 1, 0, "SessionEndpoint", "Only Jira instance can create Session endpoints");
    qmlRegisterUncreatableType<IssueEndpoint>(uri, 1, 0, "IssueEndpoint", "Only Jira instance can create Issue endpoints");
    qmlRegisterUncreatableType<SearchEndpoint>(uri, 1, 0, "SearchEndpoint", "Only Jira instance can create Search endpoints");
    qmlRegisterUncreatableType<UserEndpoint>(uri, 1, 0, "UserEndpoint", "Only Jira instance can create User endpoints");
}
