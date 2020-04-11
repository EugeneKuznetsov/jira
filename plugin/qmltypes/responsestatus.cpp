#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
#include "responsestatus.h"
#include "logging.h"

ResponseStatus::ResponseStatus(const qint32 statusCode, const QByteArray &data, const StatusMap &statuses)
    : QObject(nullptr)
    , m_statusCode(statusCode)
{
    qCDebug(JIRA_API_DATA) << this << "statusCode:" << statusCode << "status map:" << statuses;
    StatusMap::const_iterator status = statuses.constFind(statusCode);
    m_success = (statuses.constEnd() == status) ? false : status.value();

    // parse only known errors
    if (!m_success && statuses.constEnd() != status) {
        qCDebug(JIRA_API_DATA) << this << "error data:" << data;
        QJsonDocument json = QJsonDocument::fromJson(data);
        QJsonObject root = json.object();
        m_errors = root["errorMessages"].toVariant().toStringList();
    }
}

bool ResponseStatus::getSuccess() const
{
    return m_success;
}

int ResponseStatus::getStatusCode() const
{
    return m_statusCode;
}

const QStringList &ResponseStatus::getErrors() const
{
    return m_errors;
}
