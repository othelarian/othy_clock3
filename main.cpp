#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ocsettings.h"
#include "ocbackground.h"
//
//
#include "ocseconds.h"
#include "ocminutes.h"
#include "ochours.h"

// main function ################################

int main(int argc, char *argv[])
{
    // init global variables
    QGuiApplication app(argc, argv);
    OCsettings* ocsettings = OCsettings::getInstance();
    // set the qml custom types
    qmlRegisterType<OCbackground>("OCelements",1,0,"OCbackground");
    //
    // TODO : other types
    //
    qmlRegisterType<OChoursTicks>("OCelements",1,0,"OChoursTicks");
    qmlRegisterType<OChoursCog>("OCelements",1,0,"OChoursCog");
    qmlRegisterType<OCminutesTicks>("OCelements",1,0,"OCminutesTicks");
    qmlRegisterType<OCminutesCog>("OCelements",1,0,"OCminutesCog");
    //
    // seconds ticks
    //
    qmlRegisterType<OCsecondsCog>("OCelements",1,0,"OCsecondsCog");
    // load the engine
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ocsettings",ocsettings);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
