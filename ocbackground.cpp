#include "ocbackground.h"

#include <QDebug>

OCbackground::OCbackground(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OCbackground::paint(QPainter *painter)
{
    // set basic parameters
    int dim = qMin(width(),height());
    double scale = dim/300.0;
    QPointF center(width()/2,height()/2);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(center);
    painter->setPen(Qt::NoPen);
    int size, thick;
    QRectF maxrect;
    QRectF minrect;
    // painting months background
    //
    // painting days background
    //
    // NOTE : add weeks separators ?
    //
    // painting week background
    //
    //
    // painting hours background
    painter->save();
    size = int(m_settings->getSize("size_hours_bg_dim")*scale);
    thick = int(m_settings->getSize("size_hours_bg_thick")*scale);
    maxrect.setRect(-size/2,-size/2,size,size);
    minrect.setRect(-(size-thick)/2,-(size-thick)/2,size-thick,size-thick);
    painter->setBrush(QBrush(m_settings->getColor("col_hours_bg")));
    QPainterPath hoursPath;
    hoursPath.addEllipse(maxrect);
    hoursPath.addEllipse(minrect);
    painter->drawPath(hoursPath);
    painter->restore();
    // painting minutes background
    //
    // painting seconds background
    //
    //
}

void OCbackground::setHoursValue(int value)
{
    m_hours_value = (value < 12)? value : value-12;
}
