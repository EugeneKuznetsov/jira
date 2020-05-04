import QtQuick 2.14
import QtTest 1.14
import Jira 1.0

TestCase {
    id: root

    name: "[User]"

    function test_createUserObject() {
        try {
            verify(Qt.createQmlObject("import Jira 1.0; User { }", root) === null)
        } catch (err) {
        }
    }
}
