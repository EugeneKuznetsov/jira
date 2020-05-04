import QtQuick 2.14
import QtTest 1.14
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
        compare(options.server.toString(), "http://localhost:2990/jira",
                "Default server was changed")
        compare(options.username, "", "Default username was changed")
        compare(options.password, "", "Default password was changed")
    }

    function test_change_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        var options = jira.options
        options.server = "http://server"
        options.username = "username"
        options.password = "password"
        compare(options.server.toString(), "http://server",
                "Default server was not changed")
        compare(options.username, "username",
                "Default username was not changed")
        compare(options.password, "password",
                "Default password was not changed")

        options = Qt.createQmlObject("import Jira 1.0; Options { }", root)
        optionsSpy.clear()
        optionsSpy.target = jira
        optionsSpy.signalName = "optionsChanged"
        jira.options = options
        optionsSpy.wait(100)
        verify(optionsSpy.count === 1,
               "Change of options did not produce signal optionsChanged")
    }

    function test_login_with_invalid_callback() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.login(null)
        tryVerify(function () {
            return errorSpy.count === 0
        }, 1000, "Issue call produced a network error")
    }

    function test_login_with_change_options_jira_server() {
        var jira = Qt.createQmlObject(
                    "import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\" } }",
                    root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function cb(status) {
            fail("Login callback was invoked for a first server")
        }
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1,
               "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0,
               "Connection to the first server did not produced networkErrorDetails error string")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        callback = function cb(status) {
            visited = true
            compare(status.success, false,
                    "Login to changed (online) server was successful")
            compare(status.errors.length, 1)
        }
        jira.options.server = "https://jira.atlassian.com/"
        jira.login(callback)
        tryVerify(function () {
            return visited === true
        }, 5000, "Login callback was not invoked for a second server")
        verify(errorSpy.count === 0,
               "Connection to online server produced network error")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        callback = function cb(status) {
            fail("Login callback was invoked for a third server")
        }
        var options = Qt.createQmlObject(
                    "import Jira 1.0; Options { server: \"http://localhost:2999/jira\" }",
                    root)
        jira.options = options
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1,
               "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0,
               "Connection to the third server did not produced networkErrorDetails error string")
    }

    function test_login_with_change_options_jira_username_and_password() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function cb(status) {
            visited = true
            compare(status.success, false,
                    "Login to jira server was successful")
            compare(status.errors.length, 1)
        }
        jira.login(callback)
        tryVerify(function () {
            return visited === true
        }, 5000,
        "Login callback was not invoked for the first pair of username/password")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        visited = false
        callback = function cb(status) {
            visited = true
            compare(status.success, true,
                    "Login to jira server was not successful")
            compare(status.errors.length, 0)
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function () {
            return visited === true
        }, 5000,
        "Login callback was not invoked for the second pair of username/password")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_login_with_offline_server() {
        var jira = Qt.createQmlObject(
                    "import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\"} }",
                    root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function cb(status) {
            fail("Login callback was invoked when trying to connect to offline server")
        }
        jira.login(callback)
        errorSpy.wait(5000)
        verify(errorSpy.count === 1,
               "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0,
               "Connection to offline server did not produced networkErrorDetails error string")
    }

    function test_login_with_default_options() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function cb(status) {
            visited = true
            compare(status.success, false,
                    "Login to jira server was successful")
            compare(status.errors.length, 1)
        }
        jira.login(callback)
        tryVerify(function () {
            return visited === true
        }, 5000, "Login callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_login_with_valid_credentials() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {  }", root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var visited = false
        var callback = function cb(status) {
            visited = true
            compare(status.success, true,
                    "Login to jira server was not successful")
            compare(status.errors.length, 0)
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function () {
            return visited === true
        }, 5000, "Login callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_issue_with_invalid_callback() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue(null, "QTBUG-0")
        tryVerify(function () {
            return errorSpy.count === 0
        }, 1000, "Issue call produced a network error")
    }

    function test_issue_with_invalid_server() {
        var jira = Qt.createQmlObject(
                    "import Jira 1.0; Jira { options: Options { server: \"http://localhost:2999/jira\"} }",
                    root)

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        var callback = function cb(status, issue) {
            fail("Issue callback was invoked when trying to connect to offline server")
        }
        jira.issue(callback, "SANDBOX-1")
        errorSpy.wait(5000)
        verify(errorSpy.count === 1,
               "Connection to offline server did not produce network error")
        verify(errorSpy.signalArguments[0].length !== 0,
               "Connection to offline server did not produced networkErrorDetails error string")
    }

    function test_issue_with_invalid_key() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function cb(status, issue) {
            visited = true
            compare(status.success, false)
            compare(status.errors.length, 1)
            compare(issue, null,
                    "Received a valid Issue object instead of null")
            var valuesCount = 0
            for (var value in issue.expandedFields)
                valuesCount++
            compare(valuesCount, 0,
                    "Received a non-empty list of expanded fields")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue(callback, "QTBUG-0", "key", "changelog")
        tryVerify(function () {
            return visited === true
        }, 5000, "Issue callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_issue_with_valid_key() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function cb(status, issue) {
            visited = true
            compare(status.success, true)
            compare(status.errors.length, 0)
            verify(issue !== null, "Received null insted of valid Issue object")
            compare(issue.key, "QTBUG-1",
                    "Requested QTBUG-1, but received something else")
            verify(issue.expandFlags & Issue.RenderedFields,
                   "Issue QTBUG-1 cannot be expanded with changelog")
            verify(issue.expandFlags & Issue.Names,
                   "Issue QTBUG-1 cannot be expanded with names")
            verify(issue.expandFlags & Issue.Schema,
                   "Issue QTBUG-1 cannot be expanded with schema")
            verify(issue.expandFlags & Issue.Operations,
                   "Issue QTBUG-1 cannot be expanded with operations")
            verify(issue.expandFlags & Issue.EditMeta,
                   "Issue QTBUG-1 cannot be expanded with editmeta")
            verify(issue.expandFlags & Issue.Changelog,
                   "Issue QTBUG-1 cannot be expanded with changelog")
            verify(issue.expandFlags & Issue.VersionedRepresentations,
                   "Issue QTBUG-1 cannot be expanded with versioned representations")
            compare(issue.fields.status.name, "Closed",
                    "Status of issue QTBUG-1 is not Closed")
            compare(issue.fields.summary, undefined,
                    "Received summary text without requesting field summary")
            verify(issue.expandedFields.changelog !== undefined,
                   "Requested changelog expanded field was not received")
            compare(issue.expandedFields.changelog.total, 6,
                    "Total amount of changelog items should be")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.issue(callback, "QTBUG-1", "key,status", "changelog")
        tryVerify(function () {
            return visited === true
        }, 5000, "Issue callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_search_with_invalid_jql() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function cb(status, issues, total) {
            visited = true
            compare(status.success, false)
            compare(status.errors.length, 1)
            compare(issues.length, 0,
                    "Expected 0 issues, got " + issues.length + " instead")
            compare(total, 0, "Total is not 0")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.search(callback, "key = QTBUG-0")
        tryVerify(function () {
            return visited === true
        }, 5000, "onSearchResults callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_search_with_invalid_callback() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.search(null, "QTBUG-0")
        tryVerify(function () {
            return errorSpy.count === 0
        }, 1000, "Search call produced a network error")
    }

    function test_search_with_valid_jql() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function cb(status, issues, total) {
            visited = true
            compare(status.success, true)
            compare(status.errors.length, 0)
            compare(total, 2,
                    "Expected total amount of 2 issues, received " + total + " instead")
            compare(issues.length, 2,
                    "Expected 2 issues, got " + issues.length + " instead")
            compare(issues[0].key, "QTBUG-2", "First issue is not QTBUG-2")
            compare(issues[1].key, "QTBUG-1", "Second issue is not QTBUG-1")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.search(callback, "key in (QTBUG-1, QTBUG-2)")
        tryVerify(function () {
            return visited === true
        }, 5000, "onSearchResults callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_search_with_valid_jql_huge_results() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        jira.options.server = "https://bugreports.qt.io/"

        var visited = false
        var callback = function cb(status, issues, total) {
            visited = true
            compare(status.success, true)
            compare(status.errors.length, 0)
            compare(total, 73,
                    "Expected total amount of 73 issues, received " + total + " instead")
            compare(issues.length, 10,
                    "Expected 10 issues, got " + issues.length + " instead")

            compare(issues[0].key, "QBS-160", "First issue is not QBS-160")
            compare(issues[0].fields.summary, undefined,
                    "Received summary text without requesting field summary")
            verify(issues[0].expandedFields.changelog !== undefined,
                   "Requested changelog expanded field was not received")
            compare(issues[0].expandedFields.changelog.total, 8,
                    "Total amount of changelog items should be 6")

            compare(issues[9].key, "QBS-145", "Last issue is not QBS-145")
            compare(issues[9].fields.summary, undefined,
                    "Received summary text without requesting field summary")
            verify(issues[9].expandedFields.changelog !== undefined,
                   "Requested changelog expanded field was not received")
            compare(issues[9].expandedFields.changelog.total, 9,
                    "Total amount of changelog items should be 9")
        }
        errorSpy.clear()
        errorSpy.target = jira
        errorSpy.signalName = "networkErrorDetails"
        jira.search(callback, "fixVersion in (0.2)", 5, 10, "key", "changelog")
        tryVerify(function () {
            return visited === true
        }, 5000, "onSearchResults callback was not invoked")
        verify(errorSpy.count === 0,
               "Connection to jira server produced network error")
    }

    function test_user_with_valid_username() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {  }", root)

        var loginVisited = false
        var callback = function cb(status) {
            loginVisited = true
            var userVisited = false
            if (status.success) {
                userVisited = true
                jira.user(function (userCbStatus, user) {
                    compare(userCbStatus.success, true, "User response status was not successful")
                    compare(user.name, "admin")
                    compare(user.displayName, "admin")
                    var valuesCount = 0
                    for (var value in user.avatarUrls)
                        valuesCount++
                    compare(valuesCount, 4)
                }, "admin")
                tryVerify(function () {
                    return userVisited === true
                }, 5000, "callback provided for a 'user' call was not invoked")
            }
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function () {
            return loginVisited === true
        }, 5000, "onSearchResults callback was not invoked")
    }

    function test_user_with_invalid_username() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {  }", root)

        var loginVisited = false
        var callback = function cb(status) {
            loginVisited = true
            var userVisited = false
            if (status.success) {
                userVisited = true
                jira.user(function (userCbStatus, user) {
                    compare(userCbStatus.success, false, "User response status was successful")
                    compare(userCbStatus.code, 404, "Returned code was incorrect")
                    compare(user, null, "User object was created")
                }, "admin_x_y_z")
                tryVerify(function () {
                    return userVisited === true
                }, 5000, "callback provided for a 'user' call was not invoked")
            }
        }
        jira.options.username = "admin"
        jira.options.password = "admin"
        jira.login(callback)
        tryVerify(function () {
            return loginVisited === true
        }, 5000, "onSearchResults callback was not invoked")
    }
}
