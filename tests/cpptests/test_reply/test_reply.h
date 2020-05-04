#pragma once

#include <QObject>

class ReplyTestCase : public QObject
{
    Q_OBJECT

private slots:
    void errorSignal();
    void destroySignal();
    void readySignalStatusCode_data();
    void readySignalStatusCode();
    void readySignalData_data();
    void readySignalData();
};
