#pragma once
#pragma once

#include <QObject>

class SessionTestCase : public QObject
{
    Q_OBJECT

private slots:
    void test_change_server();

    void test_session_get_with_invalid_networkmanager();
    void test_session_post_with_invalid_networkmanager();

    void test_session_get_with_invalid_hostname();
    void test_session_get_with_invalid_jira_server();
    void test_session_get_with_valid_jira_server();
    void test_session_post_with_valid_jira_server();
};
