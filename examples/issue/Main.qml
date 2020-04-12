import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import Jira 1.0

Window {
    id: root

    width: 800
    height: 600

    Rectangle {
        id: rectangle
        anchors.fill: parent

        TextField {
            id: server_address_input

            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: issue_key_input.left

            verticalAlignment: TextInput.AlignVCenter

            text: "https://bugreports.qt.io"
        }

        TextField {
            id: issue_key_input

            anchors.top: parent.top
            anchors.right: issue_open_button.left

            width: 160

            verticalAlignment: TextInput.AlignVCenter

            text: "QTBUG-1"
        }

        Button {
            id: issue_open_button

            text: "Open Issue"
            anchors.right: parent.right
            anchors.top: parent.top

            onClicked: jira.issue(onIssueData, issue_key_input.text)
        }

        Rectangle {
            anchors.top: server_address_input.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

            Text {
                id: issue_field_summary

                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 5

                font.bold: true
            }

            Text {
                id: issue_field_status

                anchors.top: issue_field_summary.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.margins: 5
            }
        }
    }

    Jira {
        id: jira

        options: Options {
            id: options
            server: server_address_input.text
        }
    }

    function onIssueData(status, issue) {
        if (status.success) {
            issue_field_summary.text = "Summary: " + issue.fields.summary
            issue_field_status.text = "Status: " + issue.fields.status.name
        } else {
            issue_field_summary.text = status.errors[0]
            issue_field_status.text = ""
        }
    }

    Component.onCompleted: root.visible = true
}
