#include <QtQuickTest>
#include <QQmlEngine>
#include "plugintest.h"

void SetupTestCase::qmlEngineAvailable(QQmlEngine *engine) {
    engine->addImportPath("../plugin/imports");
}

QUICK_TEST_MAIN_WITH_SETUP(JiraQmlPluginTest, SetupTestCase)
