#include <QTest>
#include <QSignalSpy>
#include <QUrlQuery>
#include "network/session.h"
#include "network/reply.h"
#include "qmltypes/options.h"
#include "cutemockserver.h"
#include "test_endpoint.h"

void EndpointTestCase::testPost_data()
{
    QTest::addColumn<QUrl>("server");
    QTest::addColumn<QUrl>("baseUri");
    QTest::addColumn<QByteArray>("payload");
    QTest::addColumn<bool>("expectedError");
    QTest::addColumn<bool>("expectedData");

    QTest::newRow("Host not found") << QUrl("http://a.b.c.d.e.f") << QUrl("/") << QByteArray("") << true << false;
    QTest::newRow("Successful POST") << QUrl("http://localhost:8080") << QUrl("/") << QByteArray("") << false << true;
}

void EndpointTestCase::testPost()
{
    QFETCH(QUrl, server);
    QFETCH(QUrl, baseUri);
    QFETCH(QByteArray, payload);
    QFETCH(bool, expectedError);
    QFETCH(bool, expectedData);

    CuteMockServer mockServer;
    mockServer.listen(8080);
    Jira *jiraInstance = new Jira;
    Options *mockOptions = new Options(jiraInstance);
    mockOptions->setServer(server);
    jiraInstance->setOptions(mockOptions);
    QJSValue fakeCallback;
    AnyDerivedEndpoint *anyEndpoint = new AnyDerivedEndpoint(baseUri, fakeCallback, jiraInstance);

    Reply *reply = anyEndpoint->post(payload);

    QSignalSpy errorSpy(jiraInstance, &Jira::networkErrorDetails);
    QSignalSpy endpointDestroyedSpy(anyEndpoint, &AnyDerivedEndpoint::destroyed);
    QSignalSpy readySpy(reply, &Reply::ready);
    if (expectedError)
        QCOMPARE(errorSpy.wait(3000), expectedError);
    if (expectedData)
        QCOMPARE(readySpy.wait(500), expectedData);
    QCOMPARE(errorSpy.count(), expectedError ? 1 : 0);
    QCOMPARE(readySpy.count(), expectedData ? 1 : 0);
    QVERIFY(endpointDestroyedSpy.wait(500));
    delete jiraInstance;
}

void EndpointTestCase::testGetQuery_data()
{
    QTest::addColumn<QUrl>("server");
    QTest::addColumn<QUrl>("baseUri");
    QTest::addColumn<bool>("expectedError");
    QTest::addColumn<bool>("expectedData");

    QTest::newRow("Host not found") << QUrl("http://a.b.c.d.e.f") << QUrl("/") << true << false;
    QTest::newRow("Successful GET") << QUrl("http://localhost:8080") << QUrl("/") << false << true;
}

void EndpointTestCase::testGetQuery()
{
    QFETCH(QUrl, server);
    QFETCH(QUrl, baseUri);
    QFETCH(bool, expectedError);
    QFETCH(bool, expectedData);

    CuteMockServer mockServer;
    mockServer.listen(8080);
    Jira *jiraInstance = new Jira;
    Options *mockOptions = new Options(jiraInstance);
    mockOptions->setServer(server);
    jiraInstance->setOptions(mockOptions);
    QJSValue fakeCallback;
    AnyDerivedEndpoint *anyEndpoint = new AnyDerivedEndpoint(baseUri, fakeCallback, jiraInstance);

    Reply *reply = anyEndpoint->get(QUrlQuery());

    QSignalSpy errorSpy(jiraInstance, &Jira::networkErrorDetails);
    QSignalSpy endpointDestroyedSpy(anyEndpoint, &AnyDerivedEndpoint::destroyed);
    QSignalSpy readySpy(reply, &Reply::ready);
    if (expectedError)
        QCOMPARE(errorSpy.wait(3000), expectedError);
    if (expectedData)
        QCOMPARE(readySpy.wait(500), expectedData);
    QCOMPARE(errorSpy.count(), expectedError ? 1 : 0);
    QCOMPARE(readySpy.count(), expectedData ? 1 : 0);
    QVERIFY(endpointDestroyedSpy.wait(500));
    delete jiraInstance;
}

void EndpointTestCase::testGetQueryWithSuffix_data()
{
    QTest::addColumn<QUrl>("server");
    QTest::addColumn<QUrl>("baseUri");
    QTest::addColumn<bool>("expectedError");
    QTest::addColumn<bool>("expectedData");

    QTest::newRow("Host not found") << QUrl("http://a.b.c.d.e.f") << QUrl("/") << true << false;
    QTest::newRow("Successful GET with suffix") << QUrl("http://localhost:8080") << QUrl("/") << false << true;
}

void EndpointTestCase::testGetQueryWithSuffix()
{
    QFETCH(QUrl, server);
    QFETCH(QUrl, baseUri);
    QFETCH(bool, expectedError);
    QFETCH(bool, expectedData);

    CuteMockServer mockServer;
    mockServer.listen(8080);
    Jira *jiraInstance = new Jira;
    Options *mockOptions = new Options(jiraInstance);
    mockOptions->setServer(server);
    jiraInstance->setOptions(mockOptions);
    QJSValue fakeCallback;
    AnyDerivedEndpoint *anyEndpoint = new AnyDerivedEndpoint(baseUri, fakeCallback, jiraInstance);

    Reply *reply = anyEndpoint->get("/suffix", QUrlQuery());

    QSignalSpy errorSpy(jiraInstance, &Jira::networkErrorDetails);
    QSignalSpy endpointDestroyedSpy(anyEndpoint, &AnyDerivedEndpoint::destroyed);
    QSignalSpy readySpy(reply, &Reply::ready);
    if (expectedError)
        QCOMPARE(errorSpy.wait(3000), expectedError);
    if (expectedData)
        QCOMPARE(readySpy.wait(500), expectedData);
    QCOMPARE(errorSpy.count(), expectedError ? 1 : 0);
    QCOMPARE(readySpy.count(), expectedData ? 1 : 0);
    QVERIFY(endpointDestroyedSpy.wait(500));
    delete jiraInstance;
}

EndpointTestCase::AnyDerivedEndpoint::AnyDerivedEndpoint(const QUrl &baseUri, const QJSValue &callback, Jira *parent)
    : Endpoint(baseUri, callback, parent)
{
}

Reply *EndpointTestCase::AnyDerivedEndpoint::post(const QByteArray &payload)
{
    return Endpoint::post(payload);
}

Reply *EndpointTestCase::AnyDerivedEndpoint::get(const QUrlQuery &query)
{
    return Endpoint::get(query);
}

Reply *EndpointTestCase::AnyDerivedEndpoint::get(const QString &baseUriSuffix, const QUrlQuery &query)
{
    return Endpoint::get(baseUriSuffix, query);
}

QTEST_GUILESS_MAIN(EndpointTestCase)
