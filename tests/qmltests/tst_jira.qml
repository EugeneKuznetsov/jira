import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Jira]"

    SignalSpy {
        id: spy
    }

    function test_default_options() {
        verify(false, "Unit test not implemented")
    }

    function test_change_options_jira_server() {
        verify(false, "Unit test not implemented")
    }

    function test_change_options_jira_username() {
        verify(false, "Unit test not implemented")
    }

    function test_change_options_jira_password() {
        verify(false, "Unit test not implemented")
    }

    function test_login_with_offline_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://127.0.0.1:2999/jira\"} }", root)

        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, false, "Login to offline server was successful")
            verify(jira.getLastError().length() !== 0, "Error message was still empty after connection to offline server")
        }

        spy.clear()
        spy.target = jira
        spy.signalName = "lastErrorChanged"
        jira.login(callback)

        tryVerify(function() { return visited === true }, 3000, "Login callback was not invoked")
        compare(spy.count, 1, "lastErrorChanged was not emitted")

        jira.destroy()
    }

    function test_login_with_default_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, false, "Login was successful with invalid credentials")
            verify(jira.getLastError().length() !== 0, "Error message was still empty after connection with default credentials")
        }

        spy.clear()
        spy.target = jira
        spy.signalName = "lastErrorChanged"
        jira.login(callback)

        tryVerify(function() { return visited === true }, 3000, "Login callback was not invoked")
        compare(spy.count, 1, "lastErrorChanged was not emitted")

        jira.destroy()
    }
}
