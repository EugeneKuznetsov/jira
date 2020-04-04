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
        issue.destroy()
    }
}
