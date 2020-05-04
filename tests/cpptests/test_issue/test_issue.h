#pragma once

#include <QObject>

class IssueTestCase : public QObject
{
    Q_OBJECT

private slots:
    void createIssueFromJsonObject();
    void createIssueFromJsonObjectWithoutFields();
    void createIssueFromEmptyJsonObject();
};
