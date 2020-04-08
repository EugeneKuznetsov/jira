#pragma once

#include <QObject>
#include <QQmlExtensionPlugin>

class JiraQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    JiraQmlPlugin(QObject *parent = nullptr);

    void registerTypes(const char *uri) override;
};
