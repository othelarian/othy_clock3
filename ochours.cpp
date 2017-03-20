#include "ochours.h"

OChours::OChours(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    // backcirclepath #############
    int rc = 150, rw = 20;
    backcirclepath.addEllipse(-rc/2,-rc/2,rc,rc);
    backcirclepath.addEllipse(-(rc-rw)/2,-(rc-rw)/2,rc-rw,rc-rw);
    // backcogpath ################
    //
    //backcogpath.addRect(20,20,60,60);
    //
    for (int i=0;i<1;i++) {
        //
        QPolygonF poly;
        //
        //
        //
    }
    //
    //backcogpath.addPolygon();
    //
    // other cogs #################
    //
}

void OChours::paint(QPainter *painter)
{
    // test values
    //
    int dimw = 200;
    int dimh = 200;
    //
    // determine the middle of the screen
    //
    int midwidth = width()/2;
    int midheight = height()/2;
    //
    qInfo() << "width: " << width() << " - midwidth: " << midwidth;
    //
    // draw the back cog
    //
    QBrush brush(QColor("#ff00ff"));
    painter->setBrush(brush);
    //
    painter->translate(midwidth,midheight);
    //
    painter->drawPath(backcirclepath);
    //
    //QPainterPath backcogpath;
    //
    //painter->drawPath(backcogpath);
    //
    //int rc = 150;
    //
    //painter->drawEllipse(midwidth-rc/2,midheight-rc/2,rc,rc);
    //
    //
}

void OChours::setValue(int value)
{
    m_value = value;
}
