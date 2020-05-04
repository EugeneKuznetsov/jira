#include <QTest>
#include <QSignalSpy>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "network/reply.h"
#include "test_reply.h"
#include "cutemockserver.h"

void ReplyTestCase::errorSignal()
{
    QNetworkAccessManager network;
    QNetworkRequest request(QUrl("https://a.b.c.d:12345/rest/api/2/serverInfo"));

    Reply reply(network.get(request), this);

    QSignalSpy errorSpy(&reply, &Reply::networkError);
    QVERIFY(errorSpy.wait(100));
}

void ReplyTestCase::destroySignal()
{
    QNetworkAccessManager network;
    QNetworkRequest request(QUrl("https://a.b.c.d:12345/rest/api/2/serverInfo"));

    Reply reply(network.get(request), this);

    QSignalSpy destroySpy(&reply, &Reply::destroy);
    QVERIFY(destroySpy.wait(100));
}

void ReplyTestCase::readySignalStatusCode_data()
{
    QTest::addColumn<QUrl>("uri");
    QTest::addColumn<int>("statusCode");

    QTest::newRow("200 OK") << QUrl("http://localhost:8080/") << 200;
    QTest::newRow("404 Not Found") << QUrl("http://localhost:8080/wrong/resource") << 404;
}

void ReplyTestCase::readySignalStatusCode()
{
    QFETCH(QUrl, uri);
    QFETCH(int, statusCode);

    CuteMockServer mockServer;
    CuteMockData cmd(200, CuteMockData::TextHtml, "");
    mockServer.setHttpRoute(CuteMockData::GET, QUrl("/"), cmd);
    mockServer.listenHttp(8080);
    QNetworkAccessManager network;
    QNetworkRequest request(uri);

    Reply reply(network.get(request), this);

    QSignalSpy readySpy(&reply, &Reply::ready);
    QVERIFY(readySpy.wait(50));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(0).toInt(), statusCode);
}

void ReplyTestCase::readySignalData_data()
{
    QTest::addColumn<QUrl>("uri");
    QTest::addColumn<QUrl>("route");
    QTest::addColumn<QByteArray>("data");

    QTest::newRow("empty") << QUrl("https://localhost:4443/no/data/") << QUrl("/no/data") << QByteArray("");
    QTest::newRow("few words") << QUrl("https://localhost:4443/data/point") << QUrl("/data/point") << QByteArray("Some Mock Data");
}

void ReplyTestCase::readySignalData()
{
    QFETCH(QUrl, uri);
    QFETCH(QUrl, route);
    QFETCH(QByteArray, data);

    CuteMockServer mockServer;
    CuteMockData cmd(200, CuteMockData::ApplicationJson, data);
    mockServer.setHttpRoute(CuteMockData::POST, route, cmd);
    mockServer.listenHttps(4443);
    QNetworkAccessManager network;
    QNetworkRequest request(uri);
    mockServer.configureSecureRequest(&request);

    Reply reply(network.post(request, ""), this);

    QSignalSpy readySpy(&reply, &Reply::ready);
    QVERIFY(readySpy.wait(50));
    auto arguments = readySpy.takeFirst();
    QCOMPARE(arguments.at(1).toByteArray(), data);
}

QTEST_GUILESS_MAIN(ReplyTestCase)
