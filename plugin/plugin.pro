TEMPLATE = lib

TARGET = $$qtLibraryTarget(qmljiraplugin)

QT = qml network

CONFIG += qt plugin

HEADERS += \
    jiraqmlplugin.h \
    logging.h \
    network/reply.h \
    network/session.h \
    qmltypes/jira.h \
    qmltypes/options.h \
    qmltypes/resources/issue.h

SOURCES += \
    jiraqmlplugin.cpp \
    logging.cpp \
    network/reply.cpp \
    network/session.cpp \
    qmltypes/jira.cpp \
    qmltypes/options.cpp \
    qmltypes/resources/issue.cpp

DISTFILES += \
    imports/qmldir

DESTDIR = $$OUT_PWD/imports/Jira

cp_qmldir.files = $$DISTFILES
cp_qmldir.path = $$DESTDIR

COPIES += cp_qmldir
