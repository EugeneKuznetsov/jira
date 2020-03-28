TEMPLATE = lib

TARGET = $$qtLibraryTarget(qmljiraplugin)

QT = qml network

CONFIG += qt plugin

HEADERS += \
    jiraqmlplugin.h \
    network/session.h \
    qmltypes/jira.h \
    qmltypes/options.h

SOURCES += \
    jiraqmlplugin.cpp \
    network/session.cpp \
    qmltypes/jira.cpp \
    qmltypes/options.cpp

DISTFILES += \
    imports/qmldir

DESTDIR = $$OUT_PWD/imports/Jira

cp_qmldir.files = $$DISTFILES
cp_qmldir.path = $$DESTDIR

COPIES += cp_qmldir
