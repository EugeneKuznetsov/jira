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

win32|unix:!macx:!android: LIBS += -L$$OUT_PWD/../../plugin/imports/Jira/ -lqmljiraplugin
android: LIBS += $$OUT_PWD/../../plugin/imports/Jira/libqmljiraplugin_$${QT_ARCH}.so
