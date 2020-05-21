# Jira REST API plugin for QML
A QML extension module for interacting with Jira Server on top of REST API calls.
Current implementation has Jira 8.8.1 Server calls with limited implementation due
to ongoing phase of development.


## Vision
Connect QML applications to Jira with only a few lines of code and easy to use API.


## Examples
Minimal code to display an Issue summary and a raw description.
```QML
import Jira 1.0
import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: root

    title: "Jira QML extension. Minimal code example"
    width: description.width
    height: description.height
    visible: true

    Text {
        id: description
    }

    Jira {
        server: "https://bugreports.qt.io"
        Component.onCompleted: issue(function(status, issue) {
            if (status.success) {
                root.title = issue.key + ". " + issue.fields["summary"];
                description.text = issue.fields["description"];
            } else if (status.errors.length) {
                description.text = status.errors[0];
            }
        }).getIssue("QTBUG-1", "summary,description")
    }

}

```

An ongoing project [Jira Tools](https://github.com/EugeneKuznetsov/JiraTools) is still
in development phase and might be checked out from time to time in order to see how
Jira QML extension could be used.


## Prerequisites for building Jira REST API plugin for QML
This project was built and tested only on Windows 10 and Ubuntu 19.10
with Qt 5.14, Python 3.8 and CMake 3.16.


## Versioning
Change in Major version of an extension module indicates a major API change, e.g.
removal or a significant change of any of existing endpoints.
Change in Minor version, indicates any other minor changes.


## License
This project developed under the MIT license.
For more information, see LICENSE.md.
