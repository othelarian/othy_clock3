#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPainterPath>

#include "ocsettings.h"
#include "ocmonths.h"
#include "ocdays.h"
#include "ocweek.h"
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
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Othy Clock 3");
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationName("Othy Software");
    OCsettings* ocsettings = OCsettings::getInstance();
    // set the qml custom types
    qmlRegisterType<OCmonthsTicks>("OCelements",1,0,"OCmonthsTicks");
    qmlRegisterType<OCmonthsCog>("OCelements",1,0,"OCmonthsCog");
    //
    // TODO : OCmonthsBg
    //
    qmlRegisterType<OCdaysTicks>("OCelements",1,0,"OCdaysTicks");
    qmlRegisterType<OCdaysCog>("OCelements",1,0,"OCdaysCog");
    //
    // TODO : OCdaysBg
    //
    qmlRegisterType<OCweekTicks>("OCelements",1,0,"OCweekTicks");
    qmlRegisterType<OCweekCog>("OCelements",1,0,"OCweekCog");
    //
    // TODO : OCweekBg
    //
    qmlRegisterType<OChoursTicks>("OCelements",1,0,"OChoursTicks");
    qmlRegisterType<OChoursCog>("OCelements",1,0,"OChoursCog");
    //
    qmlRegisterType<OChoursBg>("OCelements",1,0,"OChoursBg");
    //
    qmlRegisterType<OCminutesTicks>("OCelements",1,0,"OCminutesTicks");
    qmlRegisterType<OCminutesCog>("OCelements",1,0,"OCminutesCog");
    //
    // TODO : OCminutesBg
    //
    qmlRegisterType<OCsecondsTicks>("OCelements",1,0,"OCsecondsTicks");
    qmlRegisterType<OCsecondsCog>("OCelements",1,0,"OCsecondsCog");
    //
    // TODO : OCsecondsBg
    //
    // load the engine
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("ocsettings",ocsettings);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
