TEMPLATE = app

TARGET = test_session

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_session.h

SOURCES = test_session.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

DESTDIR = ../../../bin

QMAKE_RPATHDIR += ./imports/Jira

win32|unix:!macx: LIBS += -L$$DESTDIR/imports/Jira/ -lqmljiraplugin
