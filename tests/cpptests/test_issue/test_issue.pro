TEMPLATE = app

TARGET = test_issue

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_issue.h

SOURCES = test_issue.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

win32|unix:!macx: LIBS += -L$$OUT_PWD/../../../plugin/imports/Jira/ -lqmljiraplugin
