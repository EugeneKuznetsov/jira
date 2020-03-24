TEMPLATE = app

TARGET = qml_plugin_test

CONFIG += warn_on qmltestcase qml_debug

SOURCES = plugintest.cpp

DISTFILES += \
    tst_plugin.qml

QML_IMPORT_PATH = $$OUT_PWD/../plugin/imports

HEADERS += \
    plugintest.h
