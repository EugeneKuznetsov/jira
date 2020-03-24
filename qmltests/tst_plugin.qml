import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "Jira Plugin"

    readonly property url valid_jira_server: "https://bugreports.qt.io/"
    readonly property url invalid_jira_server: "http://127.0.0.1:12345/wrong/server"
    property Jira jira_instance

    function initTestCase() {
        jira_instance = Qt.createQmlObject("import Jira 1.0; Jira {}", root)
        verify(jira_instance != null, "Failed to create global Jira instance object")
    }

    function test_00_check_new_instance_properties() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {}", root)

        compare(jira.connectionStatus, Jira.OFFLINE, "Initial connection status is wrong")

        jira.destroy()
    }

    function test_01_connect_simple_invalid_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {}", root)

        jira.connect(invalid_jira_server)
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function test_01_connect_simple_valid_server() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {}", root)

        jira.connect(valid_jira_server)
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function cleanupTestCase() {
        verify(jira_instance != null, "Global Jira instance object is null")
        jira_instance.destroy()
    }
}
