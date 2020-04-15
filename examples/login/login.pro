TEMPLATE = app

QT = quick

SOURCES += \
    main.cpp

RESOURCES += \
    resources.qrc

DISTFILES += \
    CredentialsButton.qml \
    CredentialsLayout.qml \
    Main.qml \
    UserInputField.qml \
    UserInputLabel.qml

QML_IMPORT_PATH = $$OUT_PWD/../../plugin/imports

win32|unix:!macx: LIBS += -L$$OUT_PWD/../../plugin/imports/Jira/ -lqmljiraplugin
