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

DESTDIR = ../../bin

QML_IMPORT_PATH = $$OUT_PWD/../../bin/imports

win32|unix:!macx: LIBS += -L$$DESTDIR/imports/Jira/ -lqmljiraplugin
