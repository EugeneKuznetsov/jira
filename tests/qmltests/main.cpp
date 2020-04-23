#include <QtQuickTest>
#include <QQmlEngine>
#include "main.h"

void SetupTestSuit::qmlEngineAvailable(QQmlEngine *engine) {
   engine->addImportPath("./imports");
}

QUICK_TEST_MAIN_WITH_SETUP([Jira QML plugin], SetupTestSuit)
