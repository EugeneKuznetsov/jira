# Jira REST API plugin for QML
A QML extension module for interacting with Jira Server on top of REST API calls.
Current implementation has a limited functionality and is in phase of development.


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
        options.server: "https://bugreports.qt.io"
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
with Qt 5.14 and CMake 3.16 (should work on older versions as well,
after changing imports and CMake minimum required version).


## Versioning
At the moment Jira extension module is not synchronized with tags released in master
branch. It has a constant version 1.0 which will be changed withing upcoming
releases and will follow the version provided in tags.
Change in Major version of an extension module indicates a major API change, e.g.
an implementation of a new endpoint or change of the signature of some call.
Change in Minor version, indicates any other minor changes were valuable to be
released.


## License
This project developed under the MIT license.
For more information, see LICENSE.md.
