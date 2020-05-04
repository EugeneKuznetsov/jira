#pragma once

#include <QObject>

class SessionTestCase : public QObject
{
    Q_OBJECT

private slots:
    void testGetOffline();
    void testGetOnline_data();
    void testGetOnline();

    void testPostOffline();
    void testPostOnline_data();
    void testPostOnline();
};
