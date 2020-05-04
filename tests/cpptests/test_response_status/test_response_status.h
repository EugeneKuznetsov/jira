#pragma once

#include <QObject>

class ResponseStatusTestCase : public QObject
{
    Q_OBJECT

private slots:
    void invalidStatusCodeAndSimpleError();
    void invalidStatusCodeAndJsonError();
    void validSuccessfulStatusCodeAndInvalidStatusMap();
    void validSuccessfulStatusCodeAndValidStatusMap();
    void validErrorStatusCodeAndValidStatusMap();
};
