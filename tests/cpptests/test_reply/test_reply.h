#pragma once

#include <QObject>

class ReplyTestCase : public QObject
{
    Q_OBJECT

private slots:
    void test_reply_from_invalid_hostname();
    void test_reply_from_invalid_jira_server();
    void test_reply_from_valid_offline_jira_server();
    void test_reply_from_valid_online_jira_server();
};
