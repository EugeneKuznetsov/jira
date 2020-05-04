import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Options]"

    function test_createOptionsObject() {
        verify(Qt.createQmlObject("import Jira 1.0; Options { }", root) !== null)
    }
}
