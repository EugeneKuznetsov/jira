import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import QtQml.Models 2.1
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

            width: 200

            verticalAlignment: TextInput.AlignVCenter

            text: "https://bugreports.qt.io"
        }

        TextField {
            id: issue_search_input

            anchors.top: parent.top
            anchors.left: server_address_input.right
            anchors.right: issue_search_button.left

            verticalAlignment: TextInput.AlignVCenter

            text: "fixVersion in (0.2)"
        }

        Button {
            id: issue_search_button

            anchors.right: parent.right
            anchors.top: parent.top

            enabled: !searchInProgress

            text: "Search"

            onClicked: {
                searchInProgress = true
                currentPage = 0
                total = 0
                jira.search(issue_search_input.text, onSearchResults, 0,
                            root.maxResults)
            }
        }

        ListView {
            id: result_list

            anchors.margins: 10
            anchors.top: issue_search_button.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: status_bar.top

            clip: true

            model: searchModel
            delegate: issueDelegate
        }

        Rectangle {
            id: status_bar

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            height: 50

            Text {
                id: text_total

                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.margins: 5

                text: "Total: " + total

                width: 100
            }

            Button {
                id: search_previous_button

                anchors.left: text_total.right
                anchors.bottom: parent.bottom
                anchors.margins: 5
                width: 150

                enabled: (!searchInProgress && total !== 0
                          && root.currentPage > 0)

                text: "Prev " + maxResults

                onClicked: {
                    searchInProgress = true
                    currentPage -= maxResults
                    jira.search(issue_search_input.text, onSearchResults,
                                currentPage, root.maxResults)
                }
            }

            Button {
                id: search_next_button

                anchors.left: search_previous_button.right
                anchors.bottom: parent.bottom
                anchors.margins: 5
                width: 150

                enabled: (!searchInProgress && total !== 0
                          && currentPage + maxResults < total)

                text: "Next " + maxResults

                onClicked: {
                    searchInProgress = true
                    currentPage += maxResults
                    jira.search(issue_search_input.text, onSearchResults,
                                currentPage, root.maxResults)
                }
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

    ListModel {
        id: searchModel
    }

    Component {
        id: issueDelegate

        Item {
            width: root.width
            height: 26

            Text {
                id: text_field_key

                text: issueKey
            }

            Text {
                id: text_field_status

                anchors.left: text_field_key.right
                anchors.leftMargin: 10

                text: issueStatus
            }

            Text {
                anchors.left: text_field_status.right
                anchors.leftMargin: 10

                text: issueSummary
            }
        }
    }

    readonly property int maxResults: 15
    property int currentPage: 0
    property int total: 0
    property bool searchInProgress: false

    function onSearchResults(status, issues, total) {
        console.log("onSearchResults(issues.length=" + issues.length + ", total=" + total + ")")
        root.total = total
        searchModel.clear()
        for (var i = 0; i < issues.length; i++) {
            var issue = issues[i]
            searchModel.append({
                                   "issueKey": issue.key,
                                   "issueSummary": issue.fields.summary,
                                   "issueStatus": issue.fields.status.name
                               })
        }
        root.searchInProgress = false

        if (!status.success)
            console.log(status.errors)
    }

    Component.onCompleted: root.visible = true
}
