#include "api2endpoint.h"
#include "applicationpropertiesendpoint.h"
#include "applicationroleendpoint.h"
#include "attachmentendpoint.h"
#include "auditingendpoint.h"
#include "avatarendpoint.h"
#include "clusterendpoint.h"
#include "commentendpoint.h"
#include "componentendpoint.h"
#include "configurationendpoint.h"
#include "customfieldoptionendpoint.h"
#include "customfieldsendpoint.h"
#include "dashboardendpoint.h"
#include "fieldendpoint.h"
#include "filterendpoint.h"
#include "groupendpoint.h"
#include "groupsendpoint.h"
#include "groupuserpickerendpoint.h"
#include "indexendpoint.h"
#include "issueendpoint.h"
#include "issuelinkendpoint.h"
#include "issuelinktypeendpoint.h"
#include "issuesecurityschemesendpoint.h"
#include "issuetypeendpoint.h"
#include "issuetypeschemeendpoint.h"
#include "jqlendpoint.h"
#include "licensevalidatorendpoint.h"
#include "monitoringendpoint.h"
#include "mypreferencesendpoint.h"
#include "myselfendpoint.h"
#include "notificationschemeendpoint.h"
#include "passwordendpoint.h"
#include "permissionschemeendpoint.h"
#include "priorityendpoint.h"
#include "priorityschemesendpoint.h"
#include "projectcategoryendpoint.h"
#include "projectendpoint.h"
#include "projectvalidateendpoint.h"
#include "reindexendpoint.h"
#include "resolutionendpoint.h"
#include "roleendpoint.h"
#include "screensendpoint.h"
#include "searchendpoint.h"
#include "securitylevelendpoint.h"
#include "serverinfoendpoint.h"
#include "sessionendpoint.h"
#include "settingsendpoint.h"
#include "statuscategoryendpoint.h"
#include "statusendpoint.h"
#include "universalavatarendpoint.h"
#include "upgradeendpoint.h"
#include "userendpoint.h"
#include "versionendpoint.h"
#include "websudoendpoint.h"
#include "workflowendpoint.h"
#include "workflowschemeendpoint.h"
#include "worklogendpoint.h"
#include "agilebacklogendpoint.h"
#include "agileboardendpoint.h"
#include "agileepicendpoint.h"
#include "agileissueendpoint.h"
#include "agilesprintendpoint.h"
#include "session.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_session(nullptr)
    , m_caCertificateFile()
{
}

const QUrl &Jira::getServer() const
{
    static const QUrl emptyUrl;
    return (nullptr != m_session) ? m_session->getServer() : emptyUrl;
}

void Jira::setServer(const QUrl &server)
{
    if (nullptr != m_session && m_session->getServer() == server)
        return;

    if (nullptr != m_session)
        m_session->deleteLater();

    m_session = newSession(server);
    m_session->setupCaCertificateFile(m_caCertificateFile);
    connect(m_session, &Session::networkError, this, &Jira::networkErrorDetails);

    emit serverChanged();
}

const QString &Jira::getCaCertificateFile() const
{
    return m_caCertificateFile;
}

void Jira::setCaCertificateFile(const QString &caCertificateFile)
{
    if (m_caCertificateFile == caCertificateFile)
        return;

    m_caCertificateFile = caCertificateFile;

    if (nullptr != m_session)
        m_session->setupCaCertificateFile(m_caCertificateFile);

    emit caCertificateFileChanged(m_caCertificateFile);
}

QObject *Jira::api2(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<Api2Endpoint>(callback);
}

QObject *Jira::applicationProperties(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ApplicationPropertiesEndpoint>(callback);
}

QObject *Jira::applicationRole(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ApplicationRoleEndpoint>(callback);
}

QObject *Jira::attachment(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<AttachmentEndpoint>(callback);
}

QObject *Jira::auditing(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<AuditingEndpoint>(callback);
}

QObject *Jira::avatar(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<AvatarEndpoint>(callback);
}

QObject *Jira::cluster(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ClusterEndpoint>(callback);
}

QObject *Jira::comment(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<CommentEndpoint>(callback);
}

QObject *Jira::component(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ComponentEndpoint>(callback);
}

QObject *Jira::configuration(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ConfigurationEndpoint>(callback);
}

QObject *Jira::customFieldOption(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<CustomFieldOptionEndpoint>(callback);
}

QObject *Jira::customFields(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<CustomFieldsEndpoint>(callback);
}

QObject *Jira::dashboard(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<DashboardEndpoint>(callback);
}

QObject *Jira::field(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<FieldEndpoint>(callback);
}

QObject *Jira::filter(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<FilterEndpoint>(callback);
}

QObject *Jira::group(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<GroupEndpoint>(callback);
}

QObject *Jira::groups(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<GroupsEndpoint>(callback);
}

QObject *Jira::groupUserPicker(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<GroupUserPickerEndpoint>(callback);
}

QObject *Jira::index(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IndexEndpoint>(callback);
}

QObject *Jira::issue(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueEndpoint>(callback);
}

QObject *Jira::issueLink(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueLinkEndpoint>(callback);
}

QObject *Jira::issueLinkType(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueLinkTypeEndpoint>(callback);
}

QObject *Jira::issueSecuritySchemes(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueSecuritySchemesEndpoint>(callback);
}

QObject *Jira::issueType(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueTypeEndpoint>(callback);
}

QObject *Jira::issueTypeScheme(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<IssueTypeSchemeEndpoint>(callback);
}

QObject *Jira::jql(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<JqlEndpoint>(callback);
}

QObject *Jira::licenseValidator(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<LicenseValidatorEndpoint>(callback);
}

QObject *Jira::monitoring(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<MonitoringEndpoint>(callback);
}

QObject *Jira::myPreferences(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<MyPreferencesEndpoint>(callback);
}

QObject *Jira::mySelf(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<MySelfEndpoint>(callback);
}

QObject *Jira::notificationScheme(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<NotificationSchemeEndpoint>(callback);
}

QObject *Jira::password(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<PasswordEndpoint>(callback);
}

QObject *Jira::permissionScheme(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<PermissionSchemeEndpoint>(callback);
}

QObject *Jira::priority(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<PriorityEndpoint>(callback);
}

QObject *Jira::prioritySchemes(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<PrioritySchemesEndpoint>(callback);
}

QObject *Jira::projectCategory(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ProjectCategoryEndpoint>(callback);
}

QObject *Jira::project(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ProjectEndpoint>(callback);
}

QObject *Jira::projectValidate(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ProjectValidateEndpoint>(callback);
}

QObject *Jira::reIndex(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ReIndexEndpoint>(callback);
}

QObject *Jira::resolution(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ResolutionEndpoint>(callback);
}

QObject *Jira::role(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<RoleEndpoint>(callback);
}

QObject *Jira::screens(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ScreensEndpoint>(callback);
}

QObject *Jira::search(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SearchEndpoint>(callback);
}

QObject *Jira::securityLevel(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SecurityLevelEndpoint>(callback);
}

QObject *Jira::serverInfo(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<ServerInfoEndpoint>(callback);
}

QObject *Jira::session(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SessionEndpoint>(callback);
}

QObject *Jira::settings(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<SettingsEndpoint>(callback);
}

QObject *Jira::statusCategory(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<StatusCategoryEndpoint>(callback);
}

QObject *Jira::status(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<StatusEndpoint>(callback);
}

QObject *Jira::universalAvatar(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<UniversalAvatarEndpoint>(callback);
}

QObject *Jira::upgrade(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<UpgradeEndpoint>(callback);
}

QObject *Jira::user(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<UserEndpoint>(callback);
}

QObject *Jira::version(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<VersionEndpoint>(callback);
}

QObject *Jira::websudo(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<WebsudoEndpoint>(callback);
}

QObject *Jira::workflow(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<WorkflowEndpoint>(callback);
}

QObject *Jira::workflowScheme(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<WorkflowSchemeEndpoint>(callback);
}

QObject *Jira::worklog(QJSValue callback/* = QJSValue()*/)
{
    return endpoint<WorklogEndpoint>(callback);
}

QObject *Jira::agileBacklog(QJSValue callback)
{
    return endpoint<AgileBacklogEndpoint>(callback);
}

QObject *Jira::agileBoard(QJSValue callback)
{
    return endpoint<AgileBoardEndpoint>(callback);
}

QObject *Jira::agileEpic(QJSValue callback)
{
    return endpoint<AgileEpicEndpoint>(callback);
}

QObject *Jira::agileIssue(QJSValue callback)
{
    return endpoint<AgileIssueEndpoint>(callback);
}

QObject *Jira::agileSprint(QJSValue callback)
{
    return endpoint<AgileSprintEndpoint>(callback);
}

Session *Jira::newSession(const QUrl &server)
{
    return new Session(server, qmlEngine(this)->networkAccessManager(), this);
}
