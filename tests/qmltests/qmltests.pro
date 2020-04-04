TEMPLATE = app

TARGET = qml_plugin_test

CONFIG += warn_on qmltestcase qml_debug

HEADERS = main.h
SOURCES = main.cpp

DISTFILES += \
    tst_issue.qml \
    tst_jira.qml \
    tst_options.qml

QML_IMPORT_PATH = $$OUT_PWD/../../plugin/imports
