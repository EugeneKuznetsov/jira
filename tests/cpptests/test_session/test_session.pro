TEMPLATE = app

TARGET = test_session

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_session.h \
    ../../../plugin/network/session.h \
    ../../../plugin/network/reply.h

SOURCES = test_session.cpp \
    ../../../plugin/network/session.cpp \
    ../../../plugin/network/reply.cpp \
    ../../../plugin/utils/logging.cpp

INCLUDEPATH = ../../../plugin

DESTDIR = ../../../bin
