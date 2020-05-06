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
    Session session(QUrl("http://a.b.c.d.x.y.z:8080"), &network, nullptr);

    Reply *reply = session.get(QUrl(""));

    QVERIFY(reply != nullptr);
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY(errorSpy.wait(500));
}

void SessionTestCase::testGetOnline_data()
{
    QTest::addColumn<QString>("method");
    QTest::addColumn<int>("statusCode");

    QTest::newRow("invalid") << "POST" << 404;
    QTest::newRow("valid") << "GET" << 200;
}

void SessionTestCase::testGetOnline()
{
    QFETCH(QString, method);
    QFETCH(int, statusCode);
    CuteMockServer mockServer;
    mockServer.setHttpRoute(method, QUrl("/"), statusCode, "text/html", "");
    mockServer.listen(8080);
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.get(QUrl(""));

    QVERIFY(reply != nullptr);
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY(readySpy.wait(500));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(0).toInt(), statusCode);
}

void SessionTestCase::testPostOffline()
{
    QNetworkAccessManager network;
    Session session(QUrl("http://a.b.c.d.x.y.z:8080"), &network, nullptr);

    Reply *reply = session.post(QUrl(""), "");

    QVERIFY(reply != nullptr);
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY(errorSpy.wait(500));
}

void SessionTestCase::testPostOnline_data()
{
    QTest::addColumn<QString>("method");
    QTest::addColumn<int>("statusCode");

    QTest::newRow("invalid") << "GET" << 404;
    QTest::newRow("valid") << "POST" << 200;
}

void SessionTestCase::testPostOnline()
{
    QFETCH(QString, method);
    QFETCH(int, statusCode);
    CuteMockServer mockServer;
    mockServer.setHttpRoute(method, QUrl("/"), statusCode, "text/html", "");
    mockServer.listen(8080);
    QNetworkAccessManager network;
    Session session(QUrl("http://localhost:8080"), &network, nullptr);

    Reply *reply = session.post(QUrl(""), "");

    QVERIFY(reply != nullptr);
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY(readySpy.wait(500));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(0).toInt(), statusCode);
}

QTEST_GUILESS_MAIN(SessionTestCase)
