TEMPLATE = app

TARGET = test_reply

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_reply.h

SOURCES = test_reply.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

DESTDIR = ../../../bin

QMAKE_RPATHDIR += ./imports/Jira

win32|unix:!macx: LIBS += -L$$DESTDIR/imports/Jira/ -lqmljiraplugin
