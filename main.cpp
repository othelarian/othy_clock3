#include "othykeeper.h"
#include "othyclock.h"
#include "othysettings.h"

#include <QApplication>
#include <QtWidgets>

// SIGNATURES ##########################

void generate_needle();
void generate_ticks();
void generate_arc();
void generate_clock();

// RUN #################################

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Othy Software");
    QCoreApplication::setApplicationName("Othy Clock");
    QCoreApplication::setApplicationVersion("1.0.0");

    //
    bool mode_console = false;
    //

    //
    // TODO : Add arguments detection
    //

    // RUN MODE CONSOLE
    if (mode_console) {
        //
        // TODO : mode console
        //
        qInfo("mode console activated");
        //
        return a.exec();
    }
    // RUN MODE VISUAL
    OthyClock w;
    OthySettings settingsWin;
    QShortcut settingsSct(QKeySequence("Ctrl+S"),&w);
    QObject::connect(&settingsSct,&QShortcut::activated,
                     &settingsWin,&OthySettings::show);
    w.show();
    return a.exec();
}

// GENERATE THE CLOCK ##################

void generate_clock(QPainter &painter,int width,int height)
{
    // GET SETTINGS
    //
    // TODO : remove settings dependency
    QSettings settings;
    //
    //
    OthyKeeper* keeper = OthyKeeper::getInstance();
    //
    keeper->checkPrefs();
    //
    // BACKGROUND
    painter.fillRect(0,0,width,height,settings.value("winBackCol",QColor(0,0,0)).value<QColor>());
    // GENERATE ELEMENTS
    //
    for (int i=0;i<6;i++)
    {
        //
        //if ()
        //
    }
    //
    //
    generate_needle();
    generate_ticks();
    //
    // TODO : generate the seconds from the settings
    //
    // POINT EXAMPLE
    //
    //
    QPen secPen(QColor(0,60,220),5,Qt::SolidLine,Qt::RoundCap);
    //
    painter.translate(width/2,height/2);
    //
    //
    //
    painter.setPen(secPen);
    painter.save();
    painter.drawPoint(0,0);
    painter.restore();
    //
}

// GENERATE A NEEDLE ###################

void generate_needle()
{
    //
    //
}

// GENERATE TICKS ######################

void generate_ticks()
{
    //
    //
}

// GENERATE AN ARC #####################

void generate_arc()
{
    //
    //
}
