#pragma once

#include <QObject>
#include "qmltypes/jira.h"
#include "endpoints/endpoint.h"

class EndpointTestCase : public QObject
{
    Q_OBJECT

    class AnyDerivedEndpoint : public Endpoint
    {
    public:
        AnyDerivedEndpoint(const QUrl &baseUri, const QJSValue &callback, Jira *parent);

        Reply *post(const QByteArray &payload);
        Reply *get(const QUrlQuery &query);
        Reply *get(const QString &baseUriSuffix, const QUrlQuery &query);
    };

private slots:
    void testPost_data();
    void testPost();
    void testGetQuery_data();
    void testGetQuery();
    void testGetQueryWithSuffix_data();
    void testGetQueryWithSuffix();
};
