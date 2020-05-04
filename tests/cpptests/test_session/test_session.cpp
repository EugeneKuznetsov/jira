#include <QTest>
#include <QSignalSpy>
#include <QVariant>
#include "cutemockserver.h"
#include "network/session.h"
#include "network/reply.h"
#include "test_session.h"

void SessionTestCase::testGetOffline()
{
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.get(QUrl(""));

    QVERIFY(reply != nullptr);
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY(errorSpy.wait(100));
}

void SessionTestCase::testGetOnline_data()
{
    QTest::addColumn<int>("method");
    QTest::addColumn<int>("statusCode");

    QTest::newRow("invalid") << static_cast<int>(CuteMockData::POST) << 404;
    QTest::newRow("valid") << static_cast<int>(CuteMockData::GET) << 200;
}


void SessionTestCase::testGetOnline()
{
    QFETCH(int, method);
    QFETCH(int, statusCode);
    CuteMockServer mockServer;
    CuteMockData cmd(statusCode, CuteMockData::TextHtml, "");
    mockServer.setHttpRoute(static_cast<CuteMockData::Method>(method), QUrl("/"), cmd);
    mockServer.listenHttp(8080);
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.get(QUrl(""));

    QVERIFY(reply != nullptr);
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY(readySpy.wait(50));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(0).toInt(), statusCode);
}

void SessionTestCase::testPostOffline()
{
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.post(QUrl(""), "");

    QVERIFY(reply != nullptr);
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY(errorSpy.wait(100));
}

void SessionTestCase::testPostOnline_data()
{
    QTest::addColumn<int>("method");
    QTest::addColumn<int>("statusCode");

    QTest::newRow("invalid") << static_cast<int>(CuteMockData::GET) << 404;
    QTest::newRow("valid") << static_cast<int>(CuteMockData::POST) << 200;
}

void SessionTestCase::testPostOnline()
{
    QFETCH(int, method);
    QFETCH(int, statusCode);
    CuteMockServer mockServer;
    CuteMockData cmd(statusCode, CuteMockData::TextHtml, "");
    mockServer.setHttpRoute(static_cast<CuteMockData::Method>(method), QUrl("/"), cmd);
    mockServer.listenHttp(8080);
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.post(QUrl(""), "");

    QVERIFY(reply != nullptr);
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY(readySpy.wait(50));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(0).toInt(), statusCode);
}

QTEST_GUILESS_MAIN(SessionTestCase)
