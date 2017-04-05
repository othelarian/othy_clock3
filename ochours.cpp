#include "ochours.h"

// OChoursTicks methods #################

OChoursTicks::OChoursTicks(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OChoursTicks::paint(QPainter *painter)
{
    // set basic parameters
    int dim = qMin(width(),height());
    double scale = dim/300.0;
    QPointF center(width()/2,height()/2);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(center);
    painter->setPen(Qt::NoPen);
    // painting ticks
    //
    //
}

// OChoursCog methods ###################

OChoursCog::OChoursCog(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OChoursCog::paint(QPainter *painter)
{
    // set basic parameters
    int dim = qMin(width(),height());
    double scale = dim/300.0;
    QPointF center(width()/2,height()/2);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(center);
    painter->setPen(Qt::NoPen);
    int size = 0, thick = 0;
    int arc = 30*((m_value < 12)? m_value : m_value-12);
    // painting arc
    if (m_value != 0) {
        painter->save();
        size = int(m_settings->getSize("size_hours_arc_dim")*scale);
        thick = int(m_settings->getSize("size_hours_arc_thick")*scale);
        painter->setBrush(QBrush(m_settings->getColor("col_hours_arc")));
        if (m_value == 12) painter->drawPath(ocDrawRing(size,thick));
        else painter->drawPath(ocDrawArc(size,thick,arc,m_value < 12));
        painter->restore();
    }
    // painting cog
    painter->save();
    size = int(m_settings->getSize("size_hours_needle_dim")*scale);
    thick = int(m_settings->getSize("size_hours_needle_thick")*scale);
    int dist = int(m_settings->getSize("size_hours_needle_dist")*scale);
    int dx = int(qCos(qDegreesToRadians(double(arc-90)))*dist);
    int dy = int(qSin(qDegreesToRadians(double(arc-90)))*dist);
    painter->translate(dx,dy);
    painter->setBrush(QBrush(m_settings->getColor("col_hours_needle")));
    painter->drawPath(ocDrawRing(size,thick));
    painter->restore();
}

void OChoursCog::setValue(int value) { m_value = value; update(); }
