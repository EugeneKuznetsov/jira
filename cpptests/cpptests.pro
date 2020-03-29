TEMPLATE = app

TARGET = cpp_plugin_test

QT += qml testlib

CONFIG += warn_on testcase

HEADERS += \
    test_reply.h \
    test_session.h

SOURCES += \
    main.cpp \
    test_reply.cpp \
    test_session.cpp

INCLUDEPATH += $$PWD/../plugin
DEPENDPATH += $$PWD/../plugin

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../plugin/imports/Jira/release/ -lqmljiraplugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../plugin/imports/Jira/debug/ -lqmljiraplugin
else:unix: LIBS += -L$$PWD/../../build-jira-Desktop_Qt_5_14_1_GCC_64bit-Debug/plugin/imports/Jira/ -lqmljiraplugin

