#pragma once

#include <QQmlEngine>
#include <QObject>
#include <QJSValue>

class Session;
class SessionEndpoint;

class Jira : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl server READ getServer WRITE setServer NOTIFY serverChanged)

public:
    explicit Jira(QObject *parent = nullptr);

    const QUrl &getServer() const;
    void setServer(const QUrl &server);

signals:
    void networkErrorDetails(const QString &errorString);
    void serverChanged();

public slots:
    QObject *api2(QJSValue callback = QJSValue());
    QObject *applicationProperties(QJSValue callback = QJSValue());
    QObject *applicationRole(QJSValue callback = QJSValue());
    QObject *attachment(QJSValue callback = QJSValue());
    QObject *auditing(QJSValue callback = QJSValue());
    QObject *avatar(QJSValue callback = QJSValue());
    QObject *cluster(QJSValue callback = QJSValue());
    QObject *comment(QJSValue callback = QJSValue());
    QObject *component(QJSValue callback = QJSValue());
    QObject *configuration(QJSValue callback = QJSValue());
    QObject *customFieldOption(QJSValue callback = QJSValue());
    QObject *customFields(QJSValue callback = QJSValue());
    QObject *dashboard(QJSValue callback = QJSValue());
    QObject *field(QJSValue callback = QJSValue());
    QObject *filter(QJSValue callback = QJSValue());
    QObject *group(QJSValue callback = QJSValue());
    QObject *groups(QJSValue callback = QJSValue());
    QObject *groupUserPicker(QJSValue callback = QJSValue());
    QObject *index(QJSValue callback = QJSValue());
    QObject *issue(QJSValue callback = QJSValue());
    QObject *issueLink(QJSValue callback = QJSValue());
    QObject *issueLinkType(QJSValue callback = QJSValue());
    QObject *issueSecuritySchemes(QJSValue callback = QJSValue());
    QObject *issueType(QJSValue callback = QJSValue());
    QObject *issueTypeScheme(QJSValue callback = QJSValue());
    QObject *jql(QJSValue callback = QJSValue());
    QObject *licenseValidator(QJSValue callback = QJSValue());
    QObject *monitoring(QJSValue callback = QJSValue());
    QObject *myPreferences(QJSValue callback = QJSValue());
    QObject *mySelf(QJSValue callback = QJSValue());
    QObject *notificationScheme(QJSValue callback = QJSValue());
    QObject *password(QJSValue callback = QJSValue());
    QObject *permissionScheme(QJSValue callback = QJSValue());
    QObject *priority(QJSValue callback = QJSValue());
    QObject *prioritySchemes(QJSValue callback = QJSValue());
    QObject *projectCategory(QJSValue callback = QJSValue());
    QObject *project(QJSValue callback = QJSValue());
    QObject *projectValidate(QJSValue callback = QJSValue());
    QObject *reIndex(QJSValue callback = QJSValue());
    QObject *resolution(QJSValue callback = QJSValue());
    QObject *role(QJSValue callback = QJSValue());
    QObject *screens(QJSValue callback = QJSValue());
    QObject *search(QJSValue callback = QJSValue());
    QObject *securityLevel(QJSValue callback = QJSValue());
    QObject *serverInfo(QJSValue callback = QJSValue());
    QObject *session(QJSValue callback = QJSValue());
    QObject *settings(QJSValue callback = QJSValue());
    QObject *statusCategory(QJSValue callback = QJSValue());
    QObject *status(QJSValue callback = QJSValue());
    QObject *universalAvatar(QJSValue callback = QJSValue());
    QObject *upgrade(QJSValue callback = QJSValue());
    QObject *user(QJSValue callback = QJSValue());
    QObject *version(QJSValue callback = QJSValue());
    QObject *websudo(QJSValue callback = QJSValue());
    QObject *workflow(QJSValue callback = QJSValue());
    QObject *workflowScheme(QJSValue callback = QJSValue());
    QObject *worklog(QJSValue callback = QJSValue());

private:
    template <typename EP>
    QObject *endpoint(QJSValue callback) {
        EP *ep = new EP(callback, m_session, qjsEngine(this), qmlEngine(this));
        qmlEngine(parent())->setObjectOwnership(ep, QQmlEngine::JavaScriptOwnership);
        return ep;
    }

    Session *newSession(const QUrl &server);

private:
    Session *m_session;
};
