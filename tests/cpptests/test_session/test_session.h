#pragma once

#include <QObject>

class SessionTestCase : public QObject
{
    Q_OBJECT

private slots:
    void test_session_get_with_invalid_hostname();
    void test_session_get_with_invalid_jira_server();
    void test_session_get_with_valid_jira_server();
};
