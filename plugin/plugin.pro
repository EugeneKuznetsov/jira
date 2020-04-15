TEMPLATE = lib

TARGET = $$qtLibraryTarget(qmljiraplugin)

QT = qml network

CONFIG += qt plugin

DEFINES += EXPORT_IMPORT_MAGIC

HEADERS += \
    endpoints/issueendpoint.h \
    endpoints/searchendpoint.h \
    endpoints/sessionendpoint.h \
    utils/globals.h \
    endpoints/userendpoint.h \
    jiraqmlplugin.h \
    utils/logging.h \
    network/reply.h \
    network/session.h \
    qmltypes/jira.h \
    qmltypes/options.h \
    qmltypes/resources/user.h \
    qmltypes/responsestatus.h \
    qmltypes/resources/iss+ue.h

SOURCES += \
    endpoints/issueendpoint.cpp \
    endpoints/searchendpoint.cpp \
    endpoints/sessionendpoint.cpp \
    endpoints/userendpoint.cpp \
    jiraqmlplugin.cpp \
    utils/logging.cpp \
    network/reply.cpp \
    network/session.cpp \
    qmltypes/jira.cpp \
    qmltypes/options.cpp \
    qmltypes/resources/user.cpp \
    qmltypes/responsestatus.cpp \
    qmltypes/resources/issue.cpp

DISTFILES += \
    imports/qmldir

DESTDIR = ../bin/imports/Jira

cp_qmldir.files = $$DISTFILES
cp_qmldir.path = $$DESTDIR

COPIES += cp_qmldir
