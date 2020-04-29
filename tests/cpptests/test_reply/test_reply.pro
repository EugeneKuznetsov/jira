TEMPLATE = app

TARGET = test_reply

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_reply.h \
    ../../../plugin/network/reply.h

SOURCES = test_reply.cpp \
    ../../../plugin/network/reply.cpp \
    ../../../plugin/utils/logging.cpp

INCLUDEPATH = ../../../plugin

DESTDIR = ../../../bin
