#pragma once

#include <QObject>
#include <QStringList>
#include <QMap>

typedef QMap<int, bool> StatusMap;  // statusCode : success/error

class ResponseStatus : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool success READ getSuccess CONSTANT)
    Q_PROPERTY(int code READ getStatusCode CONSTANT)
    Q_PROPERTY(QStringList errors READ getErrors CONSTANT)

public:
    ResponseStatus(const int statusCode, const QByteArray &data, const StatusMap &statuses);

    bool getSuccess() const;
    int getStatusCode() const;
    const QStringList &getErrors() const;

private:
    int         m_statusCode;
    bool        m_success;
    QStringList m_errors;
};
