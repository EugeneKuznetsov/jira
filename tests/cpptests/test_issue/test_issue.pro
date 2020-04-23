TEMPLATE = app

TARGET = test_issue

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_issue.h

SOURCES = test_issue.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

DESTDIR = ../../../bin

win32|unix:!macx: LIBS += -L$$DESTDIR/imports/Jira/ -lqmljiraplugin
