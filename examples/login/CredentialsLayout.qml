import QtQuick 2.14
import QtQuick.Layouts 1.14

Rectangle {
    id: root

    property alias server: serverInputField.value
    property alias username: usernameInputField.value
    property alias password: passwordInputField.value
    property alias loginEnabled: loginButton.enabled
    property alias error: errorText.text

    signal login

    implicitWidth: 600
    implicitHeight: layout.implicitHeight + 100
    border {
        width: 1
        color: "#cfcfcf"
    }
    radius: 5

    GridLayout {
        id: layout

        anchors.centerIn: parent
        columns: 2
        columnSpacing: 15
        rowSpacing: 10

        Text {
            font {
                family: "Verdana"
                pointSize: 18
            }
            text: "Welcome to Jira REST API login example"
            font.bold: false

            Layout.columnSpan: 2
            Layout.bottomMargin: 20
        }
        Rectangle {
            color: "#f7bfbf"
            radius: 3
            visible: errorText.text.length != 0

            Layout.columnSpan: 2
            Layout.bottomMargin: 20
            Layout.fillWidth: true
            Layout.preferredHeight: 39

            Text {
                id: errorText

                anchors.centerIn: parent
            }
        }
        UserInputLabel {
            text: qsTr("Server")

            Layout.preferredWidth: 125
        }
        UserInputField {
            id: serverInputField
            Layout.fillWidth: true

            Layout.preferredWidth: 200
        }
        UserInputLabel {
            text: qsTr("Username")

            Layout.preferredWidth: 125
        }
        UserInputField {
            id: usernameInputField

            Layout.preferredWidth: 125

            onConfirm: login()
        }
        UserInputLabel {
            text: qsTr("Password")

            Layout.preferredWidth: 125
        }
        UserInputField {
            id: passwordInputField

            passwordMode: true

            Layout.preferredWidth: 125

            onConfirm: login()
        }
        CredentialsButton {
            id: loginButton

            text: qsTr("Log In")

            Layout.row: 5
            Layout.column: 1

            onClicked: login()
        }
    }
}
