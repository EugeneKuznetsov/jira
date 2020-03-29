#pragma once

#include <QObject>

#include "options.h"

class Session;

class Jira : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Options *options READ getOptions WRITE setOptions NOTIFY optionsChanged)

public:
    explicit Jira(QObject *parent = nullptr);

    Options *getOptions() const {
        return m_options;
    }

    void setOptions(Options *new_value);

signals:
    void optionsChanged();

private:
    Session *m_session;
    Options *m_options;
};
