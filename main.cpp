#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPainterPath>

#include "ocsettings.h"
#include "ocbackground.h"
//
//
#include "ocseconds.h"
#include "ocminutes.h"
#include "ochours.h"

// helpers ######################################

QPainterPath ocDrawRing(int size, int thick)
{
    QRectF maxrect(-size/2,-size/2,size,size);
    QRectF minrect(-(size-thick)/2,-(size-thick)/2,size-thick,size-thick);
    QPainterPath path;
    path.addEllipse(maxrect);
    path.addEllipse(minrect);
    return path;
}

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens)
{
    QRectF maxrect(-size/2,-size/2,size,size);
    QRectF minrect(-(size-thick)/2,-(size-thick)/2,size-thick,size-thick);
    QPainterPath path;
    path.moveTo(0,-(size-thick)/2);
    path.arcTo(maxrect,90,-angle+((sens)? 0 : 360));
    path.arcTo(minrect,90-angle+((sens)? 0 : 360),angle+((sens)? 0 : -360));
    return path;
}

// main function ################################

int main(int argc, char *argv[])
{
    // init global variables
    QGuiApplication app(argc, argv);
    QCoreApplication::setApplicationName("Othy Clock 3");
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationName("Othy Software");
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
