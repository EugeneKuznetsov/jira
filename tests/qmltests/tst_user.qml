import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[User]"

    function test_create_user_object() {
        try {
            var issue = Qt.createQmlObject("import Jira 1.0; User { }", root)
            verify(issue === null, "User object was successfuly created")
        } catch (err) {
        }
    }
}
