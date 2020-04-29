#include <QTest>
#include <QJsonDocument>
#include <QJsonObject>
#include "qmltypes/external/issue.h"
#include "test_issue.h"

void IssueTestCase::test_create_issue_from_json_object()
{
    QByteArray data = "{"
                          "\"expand\":\"schema\","
                          "\"id\":\"10101\","
                          "\"self\":\"http://localhost:2990/rest/api/2/issue/10101\","
                          "\"key\":\"TEST-1\","
                          "\"fields\":{"
                              "\"summary\":\"Test Summary\""
                          "},"
                          "\"changelog\":{"
                              "\"startAt\":0,"
                              "\"maxResults\":0,"
                              "\"total\":0,"
                              "\"histories\":[]"
                          "},"
                          "\"editmeta\":{"
                              "\"fields\":{}"
                          "}"
                      "}";
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    Issue issue(jsonDoc.object());

    QCOMPARE(issue.property("self").toString(), "http://localhost:2990/rest/api/2/issue/10101");
    QCOMPARE(issue.property("key").toString(), "TEST-1");
    QCOMPARE(issue.property("id").toString(), "10101");
    QCOMPARE(issue.property("expandFlags").toInt(), Issue::Schema);
    QCOMPARE(issue.property("fields").toMap()["summary"].toString(), "Test Summary");
    QCOMPARE(issue.property("expandedFields").toMap()["changelog"].toMap()["histories"].toList().size(), 0);
}

void IssueTestCase::test_create_issue_from_json_object_without_fields()
{
    QByteArray data = "{"
                          "\"expand\":\"schema,names\","
                          "\"id\":\"10102\","
                          "\"self\":\"http://localhost:2990/rest/api/2/issue/10102\","
                          "\"key\":\"TEST-2\""
                      "}";
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    Issue issue(jsonDoc.object());

    QCOMPARE(issue.property("self").toString(), "http://localhost:2990/rest/api/2/issue/10102");
    QCOMPARE(issue.property("key").toString(), "TEST-2");
    QCOMPARE(issue.property("id").toString(), "10102");
    QCOMPARE(issue.property("expandFlags").toInt(), Issue::Schema | Issue::Names);
    QCOMPARE(issue.property("fields").toMap().size(), 0);
    QCOMPARE(issue.property("expandedFields").toMap().size(), 0);
}

void IssueTestCase::test_create_issue_from_empty_json_object()
{
    QJsonObject testData;

    Issue issue(testData);

    QCOMPARE(issue.property("self").toString(), "");
    QCOMPARE(issue.property("key").toString(), "");
    QCOMPARE(issue.property("id").toString(), "");
    QCOMPARE(issue.property("expandFlags").toInt(), 0x00);
    QCOMPARE(issue.property("fields").toMap().size(), 0);
    QCOMPARE(issue.property("expandedFields").toMap().size(), 0);
}

QTEST_GUILESS_MAIN(IssueTestCase)
