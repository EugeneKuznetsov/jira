#include <QtQuickTest>
#include <QQmlEngine>
#include "main.h"

void SetupTestSuit::qmlEngineAvailable(QQmlEngine *engine) {
   engine->addImportPath("../../plugin/imports");
}

QUICK_TEST_MAIN_WITH_SETUP([Jira QML plugin], SetupTestSuit)
