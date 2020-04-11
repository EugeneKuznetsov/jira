#pragma once

#include <QObject>

class ResponseStatusTestCase : public QObject
{
    Q_OBJECT

private slots:
    void test_invalid_status_code_and_simple_error();
    void test_invalid_status_code_and_json_error();
    void test_valid_successful_status_code_and_invalid_status_map();
    void test_valid_successful_status_code_and_valid_status_map();
    void test_valid_error_status_code_and_valid_status_map();
};
