import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.14
import Jira 1.0

Window {
    id: root

    function onLoginCallback(status) {
        if (!status.success)
            credentialsLayout.error = status.errors
        else
            rootLayout.currentIndex = 1
        credentialsLayout.loginEnabled = true
    }

    function onLoginRequest() {
        credentialsLayout.error = ""
        credentialsLayout.loginEnabled = false
        jira.login(onLoginCallback)
    }

    function onNetworkError(errorString) {
        credentialsLayout.error = errorString
        credentialsLayout.loginEnabled = true
    }

    color: "#f7f7f7"
    width: Screen.width
    height: Screen.height
    minimumWidth: rootLayout.implicitWidth + 20
    minimumHeight: rootLayout.implicitHeight + 20
    maximumWidth: Screen.width
    maximumHeight: Screen.height
    visible: true

    Jira {
        id: jira

        readonly property url defaultServer: Qt.resolvedUrl(
                                                 "http://localhost:2990/jira")

        options.server: credentialsLayout.server
        options.username: credentialsLayout.username
        options.password: credentialsLayout.password

        onNetworkErrorDetails: onNetworkError(errorString)
    }

    StackLayout {
        id: rootLayout

        anchors.centerIn: parent

        CredentialsLayout {
            id: credentialsLayout

            server: jira.defaultServer

            onLogin: onLoginRequest()
        }

        Text {
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            font {
                family: "Verdana"
                pointSize: 20
            }
            text: qsTr("Welcome to") + "<br><br><b>" + jira.options.server + "</b>"
        }
    }
}
