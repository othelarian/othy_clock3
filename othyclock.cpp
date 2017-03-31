#include "othyclock.h"

// GLOBAL FUNCTIONS DECLARATIONS #######

void generate_clock(QPainter &painter,int width,int height);

// OTHYCLOCK CLASS MEMBERS #############

OthyClock::OthyClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);
    keeper = OthyKeeper::getInstance();
    setWindowTitle("Othy Clock");
    winWidth = keeper->getPrefsInt("winWidth");
    winHeight = keeper->getPrefsInt("winHeight");
    setMinimumSize(winWidth,winHeight);
    setMaximumSize(winWidth,winHeight);
}

OthyClock::~OthyClock() {}

void OthyClock::paintEvent(QPaintEvent *event)
{
    // CHECK SIZE
    int new_width = keeper->getPrefsInt("winWidth");
    int new_height = keeper->getPrefsInt("winHeight");
    if (new_width != winWidth || new_height != winHeight)
    {
        winWidth = new_width;
        winHeight = new_height;
        setMinimumSize(winWidth,winHeight);
        setMaximumSize(winWidth,winHeight);
    }
    //
    // PENS
    //
    //QPen secPen(secColor,5,Qt::SolidLine,Qt::RoundCap);

    int side = qMin(winWidth,winHeight);
    QTime time = QTime::currentTime();
    //QDate date = QDate::currentDate();

    //
    //QImage *testimg = new QImage(200,200,QImage::Format_ARGB32);
    //testimg->fill(Color);
    //
    //QPainter painter(testimg);
    QPainter painter(this);
    //
    painter.setRenderHint(QPainter::Antialiasing);
    //
    //painter.rotate(6.0*time.second());

    //
    //testimg->save("/Users/klemaitre/Devops/testimg.png");
    //
    generate_clock(painter,winWidth,winHeight);
    //
}
