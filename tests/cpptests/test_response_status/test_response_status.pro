TEMPLATE = app

TARGET = test_response_status

QT += qml testlib

CONFIG += warn_on testcase

HEADERS = test_response_status.h \
    ../../../plugin/qmltypes/internal/responsestatus.h

SOURCES = test_response_status.cpp \
    ../../../plugin/qmltypes/internal/responsestatus.cpp \
    ../../../plugin/utils/logging.cpp

INCLUDEPATH = ../../../plugin

DESTDIR = ../../../bin
