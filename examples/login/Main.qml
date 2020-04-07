import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import Jira 1.0

Window {
    id: root

    width: 500
    height: 500

    Button {
        id: login_button

        anchors.fill: parent
        anchors.margins: 5
        text: "Login"
        onClicked: {
            options.username = "admin"
            options.password = "admin"
            jira.login(onLogin)
        }
    }

    Rectangle {
        id: login_result_area

        anchors.fill: parent
        visible: false

        Text {
            id: login_result_text

            anchors.centerIn: parent
        }
    }

    Jira {
        id: jira

        options: Options {
            id: options
            // default server is http://localhost:2990/jira
        }

        onNetworkErrorDetails: console.log("Error occurred when trying to connect to server: '" + errorString + "'")
    }

    function onLogin(success) {
        login_result_text.text = (success) ? "Welcome!" : "Authentication was not successful."
        login_button.visible = false
        login_result_area.visible = true
    }

    Component.onCompleted: root.visible = true
}
