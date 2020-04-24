TEMPLATE = app

TARGET = test_response_status

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_response_status.h

SOURCES = test_response_status.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

DESTDIR = ../../../bin

QMAKE_RPATHDIR += ./imports/Jira

win32|unix:!macx: LIBS += -L$$DESTDIR/imports/Jira/ -lqmljiraplugin
