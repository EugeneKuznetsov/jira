import QtQuick 2.0
import QtTest 1.0
import Jira 1.0

TestCase {
    id: root

    name: "Plugin Test Case"

    readonly property string jira_server: "https://bugreports.qt.io/"
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

    function test_01_connect_simple_negative() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {}", root)

        jira.connect("http://127.0.0.1:12345/wrong/server")
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function test_01_connect_simple_positive() {
        var jira = Qt.createQmlObject("import Jira 1.0; Jira {}", root)

        jira.connect(jira_server)
        compare(jira.connectionStatus, Jira.CONNECTING, "Failed to initiate connection")

        jira.destroy()
    }

    function cleanupTestCase() {
        verify(jira_instance != null, "Global Jira instance object is null")
        jira_instance.destroy()
    }
}
