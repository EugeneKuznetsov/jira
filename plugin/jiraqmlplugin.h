#pragma once

#include <QObject>
#include <QQmlExtensionPlugin>

class JiraQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_DISABLE_COPY(JiraQmlPlugin)
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    explicit JiraQmlPlugin(QObject *parent = nullptr);

    void registerTypes(const char *uri) override;
};
