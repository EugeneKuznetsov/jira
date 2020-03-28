#include <QQmlEngine>
#include <QtTest/QtTest>
#include "network/session.h"
#include "test_session.h"

void SessionTestCase::initTestCase()
{
}

void SessionTestCase::cleanupTestCase()
{
}

void SessionTestCase::test_create_session_invalid_server()
{
    QQmlEngine engine;
    Session *session = new Session(QUrl("https://google.com/"), engine.networkAccessManager(), &engine);
    session->get(QUrl("/rest/api/2/serverInfo"));
}

QTEST_GUILESS_MAIN(SessionTestCase)
