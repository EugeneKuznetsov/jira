#include <QTest>
#include <QSignalSpy>
#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include "network/session.h"
#include "network/reply.h"
#include "test_session.h"

void SessionTestCase::test_change_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://jira.atlassian.com"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replyOnlineSpy(reply, &Reply::ready);
    QVERIFY2(replyOnlineSpy.wait(3000), "Ready signal was not emitted by Reply");
    auto arguments = replyOnlineSpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 200, "Connection to the first server was invalid");

    session.setServer(QUrl("/"));  // always offline server
    reply = session.get(QUrl("/"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replyOfflineSpy(reply, &Reply::ready);
    QVERIFY2(replyOfflineSpy.wait(3000), "Ready signal was not emitted by Reply");
    arguments = replyOfflineSpy.takeLast();
    QVERIFY2(arguments.at(0).toInt() == 0, "Connection to the second server was invalid");
}

void SessionTestCase::test_session_get_with_invalid_networkmanager()
{
    QQmlEngine engine;
    Session session(QUrl(""), nullptr, &engine);

    Reply *reply = session.get(QUrl(""));
    QVERIFY2(nullptr == reply, "GET method returned non-nullptr Reply object");
}

void SessionTestCase::test_session_post_with_invalid_networkmanager()
{
    QQmlEngine engine;
    Session session(QUrl(""), nullptr, &engine);

    Reply *reply = session.post(QUrl(""), QByteArray());
    QVERIFY2(nullptr == reply, "POST method returned non-nullptr Reply object");
}

void SessionTestCase::test_session_get_with_invalid_hostname()
{
    QQmlEngine engine;
    Session session(QUrl("https://a.b.c.d:12345"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_get_with_invalid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://google.com"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_get_with_valid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://jira.atlassian.com"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_post_with_valid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://jira.atlassian.com"), engine.networkAccessManager(), &engine);

    const QByteArray payload = "{\"username\": \"\", \"password\": \"\"}";
    Reply *reply = session.post(QUrl("/rest/auth/1/session"), payload);
    QVERIFY2(nullptr != reply, "POST method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

QTEST_GUILESS_MAIN(SessionTestCase)
