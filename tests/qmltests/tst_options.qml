import QtQuick 2.14
import QtTest 1.14
import Jira 1.0

TestCase {
    id: root

    name: "[Options]"

    function test_createOptionsObject() {
        verify(createTemporaryQmlObject("import Jira 1.0; Options { }", root) !== null)
    }
}
