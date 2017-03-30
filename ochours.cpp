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
    // painting back ticks
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
    // painting cog
    //
    // TODO : the cog
    //
    // painting arc
    if (m_value == 0) return;
    int arcsize = int(m_settings->getSizeHoursArcDim()*scale);
    int arcthick = int(m_settings->getSizeHoursArcThick()*scale);
    QRectF arcmaxrect(-arcsize/2,-arcsize/2,arcsize,arcsize);
    QRectF arcminrect(-(arcsize-arcthick)/2,-(arcsize-arcthick)/2,arcsize-arcthick,arcsize-arcthick);
    painter->setBrush(QBrush(m_settings->getColHoursArc()));
    if (m_value == 12) {
        QPainterPath ringPath;
        ringPath.addEllipse(arcmaxrect);
        ringPath.addEllipse(arcminrect);
        painter->drawPath(ringPath);
    }
    else {
        int arc = 30*((m_value < 12)? m_value : m_value-12);
        QPainterPath arcPath;
        if (m_value < 12) {
            arcPath.moveTo(0,-(arcsize-arcthick)/2);
            arcPath.arcTo(arcmaxrect,90,-arc);
            arcPath.arcTo(arcminrect,90-arc,arc);
        }
        else {
            arcPath.moveTo(0,-(arcsize-arcthick)/2);
            arcPath.arcTo(arcmaxrect,90,360-arc);
            arcPath.arcTo(arcminrect,90+360-arc,-360+arc);
        }
        painter->drawPath(arcPath);
    }
}

void OChoursCog::setValue(int value) { m_value = value; update(); }
