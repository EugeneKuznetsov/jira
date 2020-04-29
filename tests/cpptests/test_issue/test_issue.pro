TEMPLATE = app

TARGET = test_issue

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_issue.h \
    ../../../plugin/qmltypes/external/issue.h \

SOURCES = test_issue.cpp \
    ../../../plugin/qmltypes/external/issue.cpp \
    ../../../plugin/utils/logging.cpp

INCLUDEPATH = ../../../plugin

DESTDIR = ../../../bin
