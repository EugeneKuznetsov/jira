#pragma once

#include <QObject>

class QQmlEngine;

class SetupTestCase : public QObject
{
    Q_OBJECT

public slots:
    void qmlEngineAvailable(QQmlEngine *engine);
};
