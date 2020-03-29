#pragma once

#include <QObject>

class QQmlEngine;

class SetupTestSuit : public QObject
{
    Q_OBJECT

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);
};
