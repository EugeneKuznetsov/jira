import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Jira]"

    SignalSpy {
        id: errorSpy
    }

    SignalSpy {
        id: optionsSpy
    }

    function test_default_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        var options = jira.options
        compare(options.server.toString(), "http://localhost:2990/jira", "Default server was changed")
        compare(options.username, "", "Default username was changed")
        compare(options.password, "", "Default password was changed")
    }

    function test_change_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        var options = jira.options
        options.server = "http://server"
        options.username = "username"
        options.password = "password"
        compare(options.server.toString(), "http://server", "Default server was not changed")
        compare(options.username, "username", "Default username was not changed")
        compare(options.password, "password", "Default password was not changed")

        options = Qt.createQmlObject("import Jira 1.0; Options { }", root)
        optionsSpy.clear()
        optionsSpy.target = jira
        optionsSpy.signalName = "optionsChanged"
        jira.options = options
        optionsSpy.wait(100)
        verify(optionsSpy.count === 1, "Change of options did not produce signal optionsChanged")
    }

    function test_login_with_invalid_callback() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.login(null)
        tryVerify(function() { return errorSpy.count === 0 }, 1000, "Issue call produced a network error")
    }

    function test_login_with_change_options_jira_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\" } }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function onLoginOffline(success) { fail("Login callback was invoked for a first server") }
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1, "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0, "Connection to the first server did not produced networkErrorDetails error string")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        callback = function onLoginOnline(success) {
            visited = true
            compare(success, false, "Login to changed (online) server was successful")
        }
        jira.options.server = "https://jira.atlassian.com/"
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for a second server")
        verify(errorSpy.count === 0, "Connection to online server produced network error")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        callback = function onLoginOffline(success) { fail("Login callback was invoked for a third server") }
        var options = Qt.createQmlObject("import Jira 1.0; Options { server: \"http://localhost:2999/jira\" }", root)
        jira.options = options
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1, "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0, "Connection to the third server did not produced networkErrorDetails error string")
    }

    function test_login_with_change_options_jira_username_and_password() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, false, "Login to jira server was successful")
        }
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for the first pair of username/password")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        visited = false
        callback = function onLogin(success) {
            visited = true
            compare(success, true, "Login to jira server was not successful")
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for the second pair of username/password")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")
    }

    function test_login_with_offline_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\"} }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function onLoginOffline(success) { fail("Login callback was invoked when trying to connect to offline server") }
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1, "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0, "Connection to offline server did not produced networkErrorDetails error string")
    }

    function test_login_with_default_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, false, "Login to jira server was successful")
        }
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")
    }

    function test_login_with_valid_credentials() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {  }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, true, "Login to jira server was not successful")
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")
    }

    function test_issue_with_invalid_callback() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue("QTBUG-0", null)
        tryVerify(function() { return errorSpy.count === 0 }, 1000, "Issue call produced a network error")
    }

    function test_issue_with_invalid_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\"} }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function onIssue(issue) { fail("Issue callback was invoked when trying to connect to offline server") }
        jira.issue("SANDBOX-1", callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1, "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0, "Connection to offline server did not produced networkErrorDetails error string")
    }

    function test_issue_with_invalid_key() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function onIssue(issue) {
            visited = true
            compare(issue, null, "Received a valid Issue object instead of null")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue("QTBUG-0", callback)
        tryVerify(function() { return visited === true }, 5000, "Issue callback was not invoked")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")
    }

    function test_issue_with_valid_key() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function onIssue(issue) {
            visited = true
            verify(issue !== null, "Received null insted of valid Issue object")
            compare(issue.key, "QTBUG-1", "Requested QTBUG-1, but received something else")
            verify(issue.expand & Issue.RenderedFields, "Issue QTBUG-1 cannot be expanded with changelog")
            verify(issue.expand & Issue.Names, "Issue QTBUG-1 cannot be expanded with names")
            verify(issue.expand & Issue.Schema, "Issue QTBUG-1 cannot be expanded with schema")
            verify(issue.expand & Issue.Operations, "Issue QTBUG-1 cannot be expanded with operations")
            verify(issue.expand & Issue.EditMeta, "Issue QTBUG-1 cannot be expanded with editmeta")
            verify(issue.expand & Issue.Changelog, "Issue QTBUG-1 cannot be expanded with changelog")
            verify(issue.expand & Issue.VersionedRepresentations, "Issue QTBUG-1 cannot be expanded with versioned representations")
            compare(issue.fields.status.name, "Closed", "Status of issue QTBUG-1 is not Closed")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue("QTBUG-1", callback)
        tryVerify(function() { return visited === true }, 5000, "Issue callback was not invoked")
        verify(errorSpy.count === 0, "Connection to jira server produced network error")
    }
}
