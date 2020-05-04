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
INCLUDEPATH += ../../CuteMockServer/lib
DEPENDPATH += $$OUT_PWD/../../CuteMockServer

DESTDIR = ../../../bin

unix:!macx|win32: LIBS += -L$$OUT_PWD/../../CuteMockServer/lib/ -lqmljiraplugin
win32:!win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../../CuteMockServer/lib/qmljiraplugin.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../../CuteMockServer/lib/libqmljiraplugin.a
