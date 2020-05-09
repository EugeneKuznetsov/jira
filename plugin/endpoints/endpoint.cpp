#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/jira.h"
#include "endpoint.h"

Endpoint::Endpoint(const QUrl &baseUri, const QJSValue &callback, Jira *parent)
    : QObject(parent)
    , m_baseUri(baseUri)
    , m_callback(callback)
    , m_session(parent->activeSession())
{
}

Reply *Endpoint::post(const QByteArray &payload)
{
    return adoptReply(m_session->post(m_baseUri, payload));
}

Reply *Endpoint::get(const QUrlQuery &query)
{
    return get("", query);
}

Reply *Endpoint::get(const QString &baseUriSuffix, const QUrlQuery &query)
{
    QUrl uri(m_baseUri.toString() + baseUriSuffix);
    uri.setQuery(query);
    return adoptReply(m_session->get(uri));
}

void Endpoint::callback(const int statusCode, const QByteArray &data, const StatusMap &codes, const QJSValueList &arguments/* = {}*/)
{
    ResponseStatus *status = new ResponseStatus(statusCode, data, codes);
    qmlEngine(parent())->setObjectOwnership(status, QQmlEngine::JavaScriptOwnership);
    QJSValueList argumentsCopy(arguments);
    argumentsCopy.insert(0, qjsEngine(parent())->toScriptValue(status));
    m_callback.call(argumentsCopy);
}

Reply *Endpoint::adoptReply(Reply *reply)
{
    reply->setParent(this);
    connect(reply, &Reply::destroy, this, &Endpoint::deleteLater);
    connect(reply, &Reply::networkError, qobject_cast<Jira*>(parent()), &Jira::networkErrorDetails);
    return reply;
}
