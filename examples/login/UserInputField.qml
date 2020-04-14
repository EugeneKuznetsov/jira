import QtQuick 2.14
import QtQuick.Controls 2.14

Item {
    id: root

    property alias value: userInput.text
    property bool passwordMode: false

    signal confirm

    implicitWidth: 75
    implicitHeight: 29

    TextField {
        id: userInput

        anchors.fill: parent
        background: Rectangle {
            border {
                color: parent.activeFocus ? "#3b86ff" : "#cfcfcf"
                width: 2
            }
            color: parent.activeFocus ? "#ffffff" : (parent.hovered ? "#efefef" : "#fbfbfb")
            radius: 3
        }
        font {
            family: "Verdana"
            pointSize: 10.5
        }
        echoMode: root.passwordMode ? TextInput.Password : TextInput.Normal

        Keys.onReturnPressed: confirm()
    }
}
