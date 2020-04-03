#include <QTest>
#include <QSignalSpy>
#include <QQmlEngine>
#include <QJsonDocument>
#include <QJsonObject>
#include "network/session.h"
#include "network/reply.h"
#include "test_session.h"

void SessionTestCase::test_session_get_with_invalid_networkmanager()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl(""), nullptr, &engine);
    Reply *reply = session->get(QUrl(""));
    QVERIFY2(nullptr == reply, "GET method returned non-nullptr Reply object");
}

void SessionTestCase::test_session_post_with_invalid_networkmanager()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl(""), nullptr, &engine);
    Reply *reply = session->post(QUrl(""), QByteArray());
    QVERIFY2(nullptr == reply, "POST method returned non-nullptr Reply object");
}

void SessionTestCase::test_session_get_with_invalid_hostname()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl("https://a.b.c.d:12345"), engine.networkAccessManager(), &engine);
    Reply *reply = session->get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_get_with_invalid_jira_server()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl("https://google.com"), engine.networkAccessManager(), &engine);
    Reply *reply = session->get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_get_with_valid_jira_server()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl("http://localhost:2990/jira"), engine.networkAccessManager(), &engine);
    Reply *reply = session->get(QUrl("/rest/api/2/serverInfo"));
    QVERIFY2(nullptr != reply, "GET method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

void SessionTestCase::test_session_post_with_valid_jira_server()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl("http://localhost:2990/jira"), engine.networkAccessManager(), &engine);
    const QByteArray payload = "{\"username\": \"\", \"password\": \"\"}";
    Reply *reply = session->post(QUrl("/rest/auth/1/session"), payload);
    QVERIFY2(nullptr != reply, "POST method did not return Reply object");
    QSignalSpy replySpy(reply, &Reply::ready);
    QVERIFY2(replySpy.wait(3000), "Ready signal was not emitted by Reply");
}

QTEST_GUILESS_MAIN(SessionTestCase)
