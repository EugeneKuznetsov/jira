TEMPLATE = app

QT = quick

SOURCES += \
    main.cpp

RESOURCES += \
    resources.qrc

DISTFILES += \
    Main.qml \
    loader.js

QML_IMPORT_PATH = $$OUT_PWD/../../plugin/imports

unix:!macx: LIBS += -L$$OUT_PWD/../../plugin/imports/Jira/ -lqmljiraplugin
