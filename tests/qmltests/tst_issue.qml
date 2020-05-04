import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Issue]"

    function test_createIssueObject() {
        verify(Qt.createQmlObject("import Jira 1.0; Issue { }", root) !== null)
    }
}
