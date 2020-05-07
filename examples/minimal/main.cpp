#include <QQmlApplicationEngine>
#include <QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("./imports");
    engine.load("qrc:/Main.qml");

    return app.exec();
}
