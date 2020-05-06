#include <QtQuickTest>
#include <QQmlEngine>
#include "cutemockserver.h"
#include "main.h"

void SetupTestSuit::qmlEngineAvailable(QQmlEngine *engine) {
   engine->addImportPath("./imports");
   CuteMockServer::registerTypes();
}

QUICK_TEST_MAIN_WITH_SETUP([Jira QML plugin], SetupTestSuit)
