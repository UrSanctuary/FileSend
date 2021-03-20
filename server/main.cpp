#include "ClientList.h"
#include "FileList.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#define REGISTER_TYPE(NAME) qmlRegisterType<NAME>(#NAME, 1, 0, #NAME)

int main(int argc, char *argv[])
{
    //    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    REGISTER_TYPE(ClientList);
    REGISTER_TYPE(FileList);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
