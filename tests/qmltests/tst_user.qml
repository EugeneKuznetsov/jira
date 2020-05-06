import QtTest 1.14

TestCase {
    id: root

    name: "[User]"

    function test_createUserObject() {
        try {
            verify(createTemporaryQmlObject("import Jira 1.0; User { }", root) === null)
        } catch (err) {
        }
    }
}
