TEMPLATE = app

TARGET = test_response_status

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_response_status.h

SOURCES = test_response_status.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

win32|unix:!macx: LIBS += -L$$OUT_PWD/../../../plugin/imports/Jira/ -lqmljiraplugin
