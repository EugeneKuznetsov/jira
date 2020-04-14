import QtQuick 2.14
import QtQuick.Controls 2.14

Button {
    contentItem: Text {
        color: "#ffffff"
        font {
            family: "Verdana"
            pointSize: 10
        }
        text: parent.text
    }
    background: Rectangle {
        border {
            color: parent.activeFocus ? "#2e65bf" : "#cfcfcf"
            width: parent.activeFocus ? 3 : 0
        }
        color: parent.enabled ? ((parent.activeFocus
                                  || parent.hovered) ? "#4585ed" : "#1a68e8") : "#696a6b"
        radius: 3
    }

    Keys.onReturnPressed: clicked()
}
