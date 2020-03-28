#pragma once

#include <QObject>

class Options : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Options)

public:
    explicit Options(QObject *parent = nullptr);
};
