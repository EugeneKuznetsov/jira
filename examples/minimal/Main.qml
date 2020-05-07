import Jira 1.0
import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: root

    title: "Jira extension. Minimal example"
    width: description.width
    height: description.height
    visible: true

    Text {
        id: description
        font.pointSize: 12
    }

    Jira {
        options.server: "https://bugreports.qt.io"
        Component.onCompleted: issue(function(status, issue) {
            if (status.success) {
                root.title = issue.key + ". " + issue.fields["summary"];
                description.text = issue.fields["description"];
            } else if (status.errors.length) {
                description.text = status.errors[0];
            }
        }, "QTBUG-1", "summary,description")
    }

}
