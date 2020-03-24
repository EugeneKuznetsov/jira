TEMPLATE = lib

TARGET = $$qtLibraryTarget(qmljiraplugin)

QT = qml network

CONFIG += qt plugin

HEADERS += \
    network/session.h \
    qmltypes/jira.h \
    jiraqmlplugin.h

SOURCES += \
    network/session.cpp \
    qmltypes/jira.cpp \
    jiraqmlplugin.cpp

DISTFILES += \
    imports/qmldir

DESTDIR = $$OUT_PWD/imports/Jira

cp_qmldir.files = $$DISTFILES
cp_qmldir.path = $$DESTDIR

COPIES += cp_qmldir
