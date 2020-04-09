#include <QQmlApplicationEngine>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("../../plugin/imports");
    engine.load("qrc:/qml/Main.qml");

    return app.exec();
}
