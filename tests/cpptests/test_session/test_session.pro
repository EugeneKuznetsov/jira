TEMPLATE = app

TARGET = test_session

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_session.h

SOURCES = test_session.cpp

INCLUDEPATH += $$PWD/../../../plugin
DEPENDPATH += $$PWD/../../../plugin

unix:!macx: LIBS += -L$$OUT_PWD/../../../plugin/imports/Jira/ -lqmljiraplugin
