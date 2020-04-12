import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Issue]"

    function test_create_issue_object() {
        var issue = Qt.createQmlObject("import Jira 1.0; Issue { }", root)

        verify(issue !== null, "Failed to create Issue object")
        compare(issue.id, "", "Initial value of id is not empty")
        compare(issue.key, "", "Initial value of key is not empty")
        compare(issue.self, "", "Initial value of self is not empty")
        compare(issue.expandFlags, 0x00, "Initial value of expandFlags is incorrect")

        verify(issue.fields instanceof Object, "Type of fields is not an Object")
        var valuesCount = 0
        for (var value in issue.fields)
            valuesCount++
        compare(valuesCount, 0, "Initial size of fields is not zero")

        verify(issue.expandedFields instanceof Object, "Type of expanded fields is not an Object")
        valuesCount = 0
        for (value in issue.expandedFields)
            valuesCount++
        compare(valuesCount, 0, "Initial size of expanded fields is not zero")
    }
}
