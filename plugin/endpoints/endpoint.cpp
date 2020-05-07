#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/jira.h"
#include "endpoint.h"

Endpoint::Endpoint(const QUrl &baseUri, const QJSValue &callback, Session *session, Jira *parent)
    : QObject(parent)
    , m_baseUri(baseUri)
    , m_callback(callback)
    , m_session(session)
{
}

Reply *Endpoint::post(const QByteArray &payload)
{
    Reply *reply = m_session->post(m_baseUri, payload);
    reply->setParent(this);
    connect(reply, &Reply::destroy, this, &Endpoint::deleteLater);
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    return reply;
}

Reply *Endpoint::get(const QUrlQuery &query)
{
    QUrl uri(m_baseUri);
    uri.setQuery(query);
    Reply *reply = m_session->get(uri);
    reply->setParent(this);
    connect(reply, &Reply::destroy, this, &Endpoint::deleteLater);
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    return reply;
}

Reply *Endpoint::get(const QString &queryPrefix, const QUrlQuery &query)
{
    QUrl uri(m_baseUri.toString() + queryPrefix);
    uri.setQuery(query);
    Reply *reply = m_session->get(uri);
    reply->setParent(this);
    connect(reply, &Reply::destroy, this, &Endpoint::deleteLater);
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    return reply;
}

void Endpoint::callback(const int statusCode, const QByteArray &data, const StatusMap &codes, const QJSValueList &arguments/* = {}*/)
{
    ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
    qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
    QJSValueList argumentsCopy(arguments);
    argumentsCopy.insert(0, qjsEngine(parent())->toScriptValue(status));
    m_callback.call(argumentsCopy);
}
