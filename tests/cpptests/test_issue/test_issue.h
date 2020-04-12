#pragma once

#include <QObject>

class IssueTestCase : public QObject
{
    Q_OBJECT

private slots:
    void test_create_issue_from_json_object();
    void test_create_issue_from_json_object_without_fields();
    void test_create_issue_from_empty_json_object();
};
