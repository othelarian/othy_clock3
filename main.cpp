#include <QGuiApplication>
#include <QQmlApplicationEngine>

//#include "ocbackground.h"
#include "ocseconds.h"
#include "ocminutes.h"
#include "ochours.h"

// prototypes ###################################

// main function ################################

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //qmlRegisterType<OCbackground>
    qmlRegisterType<OCseconds>("OCelements",1,0,"OCseconds");
    qmlRegisterType<OCminutes>("OCelements",1,0,"OCminutes");
    qmlRegisterType<OChours>("OCelements",1,0,"OChours");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
