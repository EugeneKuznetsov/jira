#pragma once

#include <QObject>

class SessionTestCase : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
};
