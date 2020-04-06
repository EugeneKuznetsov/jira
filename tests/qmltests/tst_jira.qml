import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "[Jira]"

    SignalSpy {
        id: spy
    }

    function test_initial_errors() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        compare(jira.lastError, "", "Jira was created already with an error message")
        verify(jira.getCurrentErrorType() === Jira.NO_ERROR, "Jira was created already with an error type")
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
    }

    function test_login_with_change_options_jira_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\" } }", root)

        var visited = false
        var callback = function onLoginOffline(success) {
            visited = true
            compare(success, false, "Login to offline server was successful")
            verify(jira.getCurrentErrorType() === Jira.NETWORK_ERROR,
                   "Connection to offline server did not produce NETWORK_ERROR (1). Got " + jira.getCurrentErrorType() + " instead")
        }
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for a first server")

        visited = false
        callback = function onLoginOnline(success) {
            visited = true
            compare(success, false, "Login to changed (online) server was successful")
            verify(jira.getCurrentErrorType() === Jira.JIRA_USER_ERROR,
                   "Connection to changed (online) server did not produce JIRA_USER_ERROR (2). Got " + jira.getCurrentErrorType() + " instead")
        }
        jira.options.server = "http://localhost:2990/jira"
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for a second server")

        visited = false
        callback = function onLoginOffline(success) {
            visited = true
            compare(success, false, "Login to changed (offline) server was successful")
            verify(jira.getCurrentErrorType() === Jira.NETWORK_ERROR,
                   "Connection to changed (offline) server did not produce NETWORK_ERROR (1). Got " + jira.getCurrentErrorType() + " instead")
        }
        var options = Qt.createQmlObject("import Jira 1.0; Options { server: \"http://localhost:2999/jira\" }", root)
        jira.options = options
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for a third server")

        jira.destroy()
    }

    function test_login_with_change_options_jira_username_and_password() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, false, "Login to server was successful")
            verify(jira.getCurrentErrorType() === Jira.JIRA_USER_ERROR,
                   "Connection to server did not produce JIRA_USER_ERROR (2). Got " + jira.getCurrentErrorType() + " instead")
        }
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for the first pair of username/password")

        visited = false
        callback = function onLoginOnline(success) {
            visited = true
            compare(success, true, "Login with changed credentials was not successful")
            verify(jira.getCurrentErrorType() === Jira.NO_ERROR,
                   "Connection with changed (valid) credentials produced an error " + jira.getCurrentErrorType())
        }
        jira.options.username = 'admin'
        jira.options.password = 'admin'
        jira.login(callback)
        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked for the second pair of username/password")
    }

    function test_login_with_offline_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\"} }", root)

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

        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked")
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

        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked")
        compare(spy.count, 1, "lastErrorChanged was not emitted")

        jira.destroy()
    }

    function test_login_with_valid_credentials() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {  }", root)
        jira.options.username = 'admin'
        jira.options.password = 'admin'

        var visited = false
        var callback = function onLogin(success) {
            visited = true
            compare(success, true, "Login was not successful with valid credentials")
            verify(jira.getLastError().length() === 0,
                   "Error message was not empty after connection with valid credentials: " + jira.getLastError())
            verify(jira.getCurrentErrorType() === Jira.NO_ERROR,
                   "Connection with valid credentials produced an error " + jira.getCurrentErrorType())
        }

        spy.clear()
        spy.target = jira
        spy.signalName = "lastErrorChanged"
        jira.login(callback)

        tryVerify(function() { return visited === true }, 5000, "Login callback was not invoked")
        compare(spy.count, 0, "lastErrorChanged was emitted")

        jira.destroy()
    }

    function test_issue_with_invalid_key() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function onIssue(issue) {
            visited = true
            compare(issue, null, "Received a valid Issue object instead of null")
        }

        jira.issue("QTBUG-0", callback)
        tryVerify(function() { return visited === true }, 5000, "Issue callback was not invoked")

        jira.destroy()
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

        jira.issue("QTBUG-1", callback)
        tryVerify(function() { return visited === true }, 5000, "Issue callback was not invoked")

        jira.destroy()
    }
}
