import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "Jira Plugin"

    function initTestCase() {
    }

    function test_00_check_new_instance_properties() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { }", root)
        var options = Qt.createQmlObject("import Jira 1.0; Options { }", root)

        compare(jira.connectionStatus, Jira.OFFLINE, "Initial connection status is wrong")

        jira.destroy()
    }

    function test_01_connect_simple_invalid_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options {} }", root)

        jira.connect()
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function test_01_connect_simple_valid_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira { options: Options {} }", root)

        jira.connect()
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function cleanupTestCase() {
    }
}
