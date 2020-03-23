TEMPLATE = lib

TARGET = $$qtLibraryTarget(qmljiraplugin)

QT = qml

CONFIG += qt plugin

HEADERS += \
    jira.h \
    jiraqmlplugin.h

SOURCES += \
    jira.cpp \
    jiraqmlplugin.cpp

DISTFILES += \
    imports/qmldir

DESTDIR = $$OUT_PWD/imports/Jira

cp_qmldir.files = $$DISTFILES
cp_qmldir.path = $$DESTDIR

COPIES += cp_qmldir
