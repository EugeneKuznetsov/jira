import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Options]"

    SignalSpy {
        id: spy
    }

    function test_default_values() {
        var options = Qt.createQmlObject("import Jira 1.0; Options { }", root)

        compare(options.server.toString(), "http://localhost:2990/jira", "Default server was changed")
        compare(options.username, "", "Default username was changed")
        compare(options.password, "", "Default password was changed")
    }

    function test_change_default_values() {
        var options = Qt.createQmlObject("import Jira 1.0; Options { }", root)

        spy.target = options
        spy.signalName = "serverChanged"
        options.server = Qt.resolvedUrl("https://some_other_server/jira")
        tryCompare(spy, "count", 1, 500, "Server property change signal was not emitted")
        compare(options.server, Qt.resolvedUrl("https://some_other_server/jira"), "Default server was not changed")

        spy.clear()
        spy.target = options
        spy.signalName = "usernameChanged"
        options.username = "admin"
        tryCompare(spy, "count", 1, 500, "Username property change signal was not emitted")
        compare(options.username, "admin", "Default username was not changed")

        spy.clear()
        spy.target = options
        spy.signalName = "passwordChanged"
        options.password = "admin"
        tryCompare(spy, "count", 1, 500, "Password property change signal was not emitted")
        compare(options.password, "admin", "Default password was not changed")
    }
}
