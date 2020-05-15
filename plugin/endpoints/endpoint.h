#pragma once

#include <QQmlEngine>
#include <QObject>
#include <QJSValue>
#include <QUrl>
#include "qmltypes/internal/responsestatus.h"

class Jira;
class Session;
class Reply;

class Endpoint : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QJSValue callback READ getCallback WRITE setCallback NOTIFY callbackChanged)

protected:
    Endpoint(const QUrl &baseUri, const QJSValue &callback, Jira *parent);

    bool isCallbackValid() const;

    Reply *post(const QByteArray &payload);
    Reply *get(const QUrlQuery &query);
    Reply *get(const QString &baseUriSuffix, const QUrlQuery &query);

    void callback(const int statusCode, const QByteArray &data, const StatusMap &codes, const QJSValueList &arguments = {});

    template <typename T>
    QJSValue jsArg(const T &value) {
        return qjsEngine(parent())->toScriptValue(value);
    }

signals:
    void callbackChanged();

public:
    const QJSValue &getCallback() const;
    void setCallback(const QJSValue &callback);

private:
    Reply *adoptReply(Reply *reply);

private:
    const QUrl m_baseUri;
    QJSValue   m_callback;
    Session    *m_session;
};

