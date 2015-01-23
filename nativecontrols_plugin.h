#ifndef NATIVECONTROLS_PLUGIN_H
#define NATIVECONTROLS_PLUGIN_H

#include <QQmlExtensionPlugin>

class NativeControlsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // NATIVECONTROLS_PLUGIN_H

