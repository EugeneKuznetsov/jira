#pragma once

#include <QObject>
#include <QUrl>

class SessionTestCase : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_create_session_invalid_server();
};
