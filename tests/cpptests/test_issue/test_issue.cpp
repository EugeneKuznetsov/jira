#include <QTest>
#include <QJsonDocument>
#include <QJsonObject>
#include "qmltypes/resources/issue.h"
#include "test_issue.h"

void IssueTestCase::test_create_issue_from_json_document()
{
    QJsonObject issueObject;
    issueObject.insert("self", "http://localhost:2990/rest/api/2/issue/10001");
    issueObject.insert("key", "TEST-1");
    issueObject.insert("id", "10001");
    issueObject.insert("expand", "changelog");
    QJsonObject fieldsObject;
    QJsonObject fieldSummary;
    fieldsObject.insert("summary", "Some summary");
    issueObject.insert("fields", fieldsObject);
    QJsonDocument testData(issueObject);

    Issue issue(testData);

    QCOMPARE(issue.property("self").toString(), "http://localhost:2990/rest/api/2/issue/10001");
    QCOMPARE(issue.property("key").toString(), "TEST-1");
    QCOMPARE(issue.property("id").toString(), "10001");
    QCOMPARE(issue.property("expand").toUInt(), Issue::Changelog);
    QCOMPARE(issue.property("fields").toMap()["summary"].toString(), "Some summary");
}

void IssueTestCase::test_create_issue_from_json_object()
{
    QJsonObject testData;
    testData.insert("self", "http://localhost:2990/rest/api/2/issue/10002");
    testData.insert("key", "TEST-2");
    testData.insert("id", "10002");
    testData.insert("expand", "schema");
    QJsonObject fieldsObject;
    QJsonObject fieldSummary;
    fieldsObject.insert("summary", "Some summary2");
    testData.insert("fields", fieldsObject);

    Issue issue(testData);

    QCOMPARE(issue.property("self").toString(), "http://localhost:2990/rest/api/2/issue/10002");
    QCOMPARE(issue.property("key").toString(), "TEST-2");
    QCOMPARE(issue.property("id").toString(), "10002");
    QCOMPARE(issue.property("expand").toUInt(), Issue::Schema);
    QCOMPARE(issue.property("fields").toMap()["summary"].toString(), "Some summary2");
}

void IssueTestCase::test_create_issue_from_empty_json_document()
{
    QJsonDocument testData;

    Issue issue(testData);

    QCOMPARE(issue.property("self").toString(), "");
    QCOMPARE(issue.property("key").toString(), "");
    QCOMPARE(issue.property("id").toString(), "");
    QCOMPARE(issue.property("expand").toUInt(), 0x00);
    QCOMPARE(issue.property("fields").toMap().size(), 0);
}

void IssueTestCase::test_create_issue_from_empty_json_object()
{
    QJsonObject testData;

    Issue issue(testData);

    QCOMPARE(issue.property("self").toString(), "");
    QCOMPARE(issue.property("key").toString(), "");
    QCOMPARE(issue.property("id").toString(), "");
    QCOMPARE(issue.property("expand").toUInt(), 0x00);
    QCOMPARE(issue.property("fields").toMap().size(), 0);
}

QTEST_GUILESS_MAIN(IssueTestCase)
