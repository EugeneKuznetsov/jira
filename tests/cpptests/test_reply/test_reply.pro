TEMPLATE = app

TARGET = test_reply

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_reply.h

SOURCES = test_reply.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

win32|unix:!macx: LIBS += -L$$OUT_PWD/../../../plugin/imports/Jira/ -lqmljiraplugin
