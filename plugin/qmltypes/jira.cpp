#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJSEngine>
#include <QJSValueList>
#include <QVariant>
#include <QQmlEngine>
#include "network/session.h"
#include "network/reply.h"
#include "responsestatus.h"
#include "logging.h"
#include "jira.h"

Jira::Jira(QObject *parent/* = nullptr*/)
    : QObject(parent)
    , m_options(new Options(this))
    , m_session(nullptr)
{
    qDebug(JIRA_INTERNAL) << this << "was created";
}

Options *Jira::getOptions() const
{
    return m_options;
}

void Jira::setOptions(Options *new_value)
{
    if (nullptr == new_value)
        return;

    if (nullptr != m_options && QQmlEngine::CppOwnership == qmlEngine(this)->objectOwnership(m_options))
        delete m_options;

    m_options = new_value;

    Q_UNUSED(activeSession(true));

    emit optionsChanged();
}

void Jira::login(const QJSValue &callback)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_API) << this << "callback is not callable";
        return;
    }

    QJsonObject root;
    root.insert("username", m_options->property("username").toString());
    root.insert("password", m_options->property("password").toString());
    QJsonDocument payload(root);
    Reply *reply = activeSession()->post(QUrl("/rest/auth/1/session"), payload.toJson());
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying:" << reply;
        reply->deleteLater();
    });
    connect(reply, &Reply::networkError, this, &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, callback](const int statusCode, const QByteArray &data) {
        ResponseStatus *status = new ResponseStatus(statusCode, data, {{200, true}, {401, false}, {403, false}});
        qmlEngine(this)->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(status)});
    });
}

void Jira::issue(const QString &issueIdOrKey, const QJSValue &callback)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_API) << this << "callback is not callable";
        return;
    }

    QString path = "/rest/api/2/issue/" + issueIdOrKey;
    Reply *reply = activeSession()->get(QUrl(path));
    qCDebug(JIRA_API) << this << "tracking following:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying:" << reply;
        reply->deleteLater();
    });
    connect(reply, &Reply::networkError, this, &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, reply, callback](const int statusCode, const QByteArray &data) {
        Issue *issue = nullptr;
        if (200 == statusCode) {
            qCDebug(JIRA_API_DATA) << this << reply << "successfuly received requested Issue";
            issue = new Issue(QJsonDocument::fromJson(data));
            qmlEngine(this)->setObjectOwnership(issue, QQmlEngine::JavaScriptOwnership);
            qCDebug(JIRA_API_DATA) << this << reply << "created new:" << issue;
        }
        ResponseStatus *status = new ResponseStatus(statusCode, data, {{200, true}, {404, false}});
        qmlEngine(this)->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{qjsEngine(this)->toScriptValue(status), qjsEngine(this)->toScriptValue(issue)});
    });
}

void Jira::search(const QString &jql, const QJSValue &callback, const int startAt/* = 0*/, const int maxResults/* = 50*/)
{
    if (!callback.isCallable()) {
        qCWarning(JIRA_API) << this << "callback is not callable";
        return;
    }

    QJsonObject root;
    root.insert("jql", jql);
    root.insert("startAt", startAt);
    root.insert("maxResults", maxResults);
    QJsonDocument payload(root);
    Reply *reply = activeSession()->post(QUrl("/rest/api/2/search"), payload.toJson());
    qCDebug(JIRA_API) << this << "tracking:" << reply;
    connect(reply, &Reply::destroy, this, [this, reply]() {
        qCDebug(JIRA_API) << this << "destroying:" << reply;
        reply->deleteLater();
    });
    connect(reply, &Reply::networkError, this, &Jira::networkErrorDetails);
    connect(reply, &Reply::ready, this, [this, reply, callback](const int statusCode, const QByteArray &data) {
        QJSValueList resultIssues;
        int total = 0;
        if (200 == statusCode) {
            qCDebug(JIRA_API_DATA) << this << reply << "successfuly received list of Issues";
            const QJsonDocument json = QJsonDocument::fromJson(data);
            const QJsonObject &root = json.object();
            const QJsonArray &issues = root["issues"].toArray();
            total = root["total"].toInt();
            for (auto issue : issues)
                resultIssues.push_back(qjsEngine(this)->toScriptValue(new Issue(issue.toObject())));
        }
        ResponseStatus *status = new ResponseStatus(statusCode, data, {{200, true}, {400, false}});
        qmlEngine(this)->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
        QJSValue callbackCopy(callback);
        callbackCopy.call(QJSValueList{
                              qjsEngine(this)->toScriptValue(status),
                              qjsEngine(this)->toScriptValue(resultIssues),
                              qjsEngine(this)->toScriptValue(total)
                          });
    });
}

Session *Jira::activeSession(bool createNewSession/* = false*/)
{
    if (createNewSession) {
        qCDebug(JIRA_INTERNAL) << this << "Requested creation of a new session";
        if (nullptr != m_session) {
            qCDebug(JIRA_INTERNAL) << this << "Old session will be deleted:" << m_session;
            delete m_session;
            m_session = nullptr;
        }
    }

    if (nullptr == m_session) {
        QQmlEngine *engine = qmlEngine(this);
        m_session = new Session(m_options->property("server").toUrl(), engine->networkAccessManager(), this);
        qCDebug(JIRA_INTERNAL) << "New session was created:" << m_session;
        QObject::connect(m_options, &Options::serverChanged, m_session, &Session::setServer);
    }

    return m_session;
}
