#ifndef RESPONSESTATUS_H
#define RESPONSESTATUS_H

#include <QObject>

class ResponseStatus : public QObject
{
    Q_OBJECT
public:
    explicit ResponseStatus(QObject *parent = nullptr);

signals:

};

#endif // RESPONSESTATUS_H
