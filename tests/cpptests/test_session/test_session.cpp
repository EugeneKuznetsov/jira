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

    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY2(readySpy.wait(5000), "Ready signal was not emitted by Reply");
    auto arguments = readySpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 200, "Connection to the first server was invalid");

    session.setServer(QUrl("/"));  // always offline server
    reply = session.get(QUrl("/"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY2(errorSpy.wait(5000), "Error signal was not emitted by Reply");
    arguments = errorSpy.takeFirst();
    QVERIFY2(!arguments.at(0).toString().isEmpty(), "Connection to offline host did not produce any error string");
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
    QSignalSpy errorSpy(reply, &Reply::networkError);
    QVERIFY2(errorSpy.wait(5000), "Error signal was not emitted by Reply");
    auto arguments = errorSpy.takeFirst();
    QVERIFY2(!arguments.at(0).toString().isEmpty(), "Connection to offline host did not produce any error string");
}

void SessionTestCase::test_session_get_with_invalid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://google.com"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY2(readySpy.wait(5000), "Ready signal was not emitted by Reply");
    auto arguments = readySpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 404, "Connection to invalid jira server did not produce statusCode 404");
}

void SessionTestCase::test_session_get_with_valid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://jira.atlassian.com"), engine.networkAccessManager(), &engine);

    Reply *reply = session.get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY2(readySpy.wait(5000), "Ready signal was not emitted by Reply");
    auto arguments = readySpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 200, "Connection to jira server did not produce statusCode 200");
}

void SessionTestCase::test_session_post_with_valid_jira_server()
{
    QQmlEngine engine;
    Session session(QUrl("https://jira.atlassian.com"), engine.networkAccessManager(), &engine);

    const QByteArray payload = "{\"username\": \"\", \"password\": \"\"}";
    Reply *reply = session.post(QUrl("/rest/auth/1/session"), payload);
    QVERIFY2(nullptr != reply, "POST method did not return Reply object");
    QSignalSpy readySpy(reply, &Reply::ready);
    QVERIFY2(readySpy.wait(5000), "Ready signal was not emitted by Reply");
    auto arguments = readySpy.takeFirst();
    QVERIFY2(arguments.at(0).toInt() == 401, "Connection to jira server did not produce statusCode 401");
}

QTEST_GUILESS_MAIN(SessionTestCase)
