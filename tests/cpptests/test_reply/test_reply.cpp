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
    Reply *reply = new Reply(network->get(request), this);
    connect(reply, &Reply::ready, this, [reply](const int statusCode, const QByteArray &){
        QCOMPARE(statusCode, 0);
        QVERIFY2(!reply->getErrorString().isEmpty(), "Connection to invalid host did not produce any error string");
    });
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void ReplyTestCase::test_reply_from_invalid_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://google.com/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");
    Reply *reply = new Reply(network->get(request), this);
    connect(reply, &Reply::ready, this, [reply](const int statusCode, const QByteArray &data){
        QCOMPARE(statusCode, 404);
        QVERIFY2(!data.isEmpty(), "At least some data expected to be returned from an 'invalid' server");
        QVERIFY2(reply->getErrorString().isEmpty(), "Connection to invalid Jira server produced an error string");
    });
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void ReplyTestCase::test_reply_from_valid_offline_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("http://localhost:299/jira/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("X-Atlassian-Token", "no-check");
    Reply *reply = new Reply(network->get(request), this);
    connect(reply, &Reply::ready, this, [reply](const int statusCode, const QByteArray &){
        QCOMPARE(statusCode, 0);
        QVERIFY2(!reply->getErrorString().isEmpty(), "Connection to a valid Jira server in offline did not produce an error string");
    });
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void ReplyTestCase::test_reply_from_valid_online_jira_server()
{
    QQmlEngine engine;
    QNetworkAccessManager *network = engine.networkAccessManager();
    QNetworkRequest request(QUrl("https://jira.atlassian.com/rest/api/2/serverInfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    Reply *reply = new Reply(network->get(request), this);
    connect(reply, &Reply::ready, this, [reply](const int statusCode, const QByteArray &data){
        QCOMPARE(statusCode, 200);
        QJsonDocument json = QJsonDocument::fromJson(data);
        QJsonObject root = json.object();
        QVERIFY2(!root.isEmpty(), "Despite successful return code, data does not contain JSON object");
        QVERIFY2(reply->getErrorString().isEmpty(), "Connection to a valid Jira server produced an error string");
    });
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

QTEST_GUILESS_MAIN(ReplyTestCase)
