#include <QTest>
#include <QSignalSpy>
#include <QQmlEngine>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include "network/reply.h"
#include "test_reply.h"

void ReplyTestCase::test_reply_from_invalid_hostname()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://a.b.c.d:12345/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");

    Reply reply(network->get(request), this);

    QSignalSpy destroySpy(&reply, &Reply::destroy);
    QSignalSpy errorSpy(&reply, &Reply::networkError);
    QSignalSpy readySpy(&reply, &Reply::ready);

    QVERIFY2(destroySpy.wait(5000), "Destroy signal was not emitted by Reply");
    QVERIFY2(errorSpy.count() == 1, "Error signal was not emitted by Reply");
    auto arguments = errorSpy.takeFirst();
    QVERIFY2(!arguments.at(0).toString().isEmpty(), "Connection to invalid host did not produce any error string");
    QVERIFY2(readySpy.count() == 0, "Ready signal was emitted by Reply");
}

void ReplyTestCase::test_reply_from_invalid_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://google.com/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");

    Reply reply(network->get(request), this);

    QSignalSpy destroySpy(&reply, &Reply::destroy);
    QSignalSpy errorSpy(&reply, &Reply::networkError);
    QSignalSpy readySpy(&reply, &Reply::ready);

    QVERIFY2(destroySpy.wait(5000), "Destroy signal was not emitted by Reply");
    QVERIFY2(errorSpy.count() == 0, "Error signal was emitted by Reply");
    QVERIFY2(readySpy.count() == 1, "Ready signal was not emitted by Reply");
    auto arguments = readySpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 404, "Connection to invalid jira server did not produce status code 404");
    QVERIFY2(!arguments.at(1).toByteArray().isEmpty(), "At least some data expected to be returned from an 'invalid' server");
}

void ReplyTestCase::test_reply_from_valid_offline_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://localhost:299/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");

    Reply reply(network->get(request), this);

    QSignalSpy destroySpy(&reply, &Reply::destroy);
    QSignalSpy errorSpy(&reply, &Reply::networkError);
    QSignalSpy readySpy(&reply, &Reply::ready);
    QVERIFY2(destroySpy.wait(5000), "Destroy signal was not emitted by Reply");
    QVERIFY2(errorSpy.count() == 1, "Error signal was not emitted by Reply");
    auto arguments = errorSpy.takeFirst();
    QVERIFY2(!arguments.at(0).toString().isEmpty(), "Connection to offline jira server did not produce any error string");
    QVERIFY2(readySpy.count() == 0, "Ready signal was emitted by Reply");
}

void ReplyTestCase::test_reply_from_valid_online_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://jira.atlassian.com/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    Reply reply(network->get(request), this);
    connect(&reply, &Reply::ready, this, [](const int statusCode, const QByteArray &data){
        QCOMPARE(statusCode, 200);
        QJsonDocument json = QJsonDocument::fromJson(data);
        QJsonObject root = json.object();
        QVERIFY2(!root.isEmpty(), "Despite successful return code, data does not contain JSON object");
    });

    QSignalSpy destroySpy(&reply, &Reply::destroy);
    QSignalSpy errorSpy(&reply, &Reply::networkError);
    QSignalSpy readySpy(&reply, &Reply::ready);
    QVERIFY2(destroySpy.wait(5000), "Destroy signal was not emitted by Reply");
    QVERIFY2(errorSpy.count() == 0, "Error signal was emitted by Reply");
    QVERIFY2(readySpy.count() == 1, "Ready signal was not emitted by Reply");
}

QTEST_GUILESS_MAIN(ReplyTestCase)
