import QtTest 1.14

TestCase {
    id: root

    name: "[Issue]"

    function test_createIssueObject() {
        verify(createTemporaryQmlObject("import Jira 1.1; Issue { }", root) !== null)
    }
}
