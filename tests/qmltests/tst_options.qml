import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Options]"

    function test_default_values() {
        var options = Qt.createQmlObject("import Jira 1.0; Options { }", root)
        compare(options.server.toString(), "http://localhost:2990/jira", "Default server was changed")
        compare(options.username, "", "Default username was changed")
        compare(options.password, "", "Default password was changed")
        options.destroy()
    }

    function test_change_default_values() {
        var options = Qt.createQmlObject("import Jira 1.0; Options { }", root)
        options.server = Qt.resolvedUrl("https://127.0.0.1:2990/jira")
        compare(options.server, Qt.resolvedUrl("https://127.0.0.1:2990/jira"), "Default server was not changed")
        options.username = "admin"
        compare(options.username, "admin", "Default username was not changed")
        options.password = "admin"
        compare(options.password, "admin", "Default password was not changed")
        options.destroy()
    }
}
