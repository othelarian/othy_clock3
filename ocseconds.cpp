#include "ocseconds.h"

OCseconds::OCseconds(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_value = 0;
    m_even = true;
}

void OCseconds::paint(QPainter *painter)
{
    if (m_value == 0 && m_even) return;
    int dim = qMax(width(),height());
    QPointF center(width()/2,height()/2);
    //
    QBrush brush(QColor("#0045ff"));
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    //painter->setRenderHint(QPainter::Antialiasing);
    //
    painter->translate(center);
    QPainterPath secondsPath;
    //
    //qInfo() << "second paint" << m_value;
    //
    if (m_value == 0 && !m_even) {
        //
        //
    }
    else {
        if (m_even) {
            //
            //
        }
        else {
            //
            //
        }
    }
    //
    int arc = 6*m_value;
    //
    secondsPath.arcTo(QRectF(-100,-100,200,200),90,-arc);
    //
    secondsPath.arcTo(QRectF(-90,-90,180,180),90-arc,arc);
    //
    //
    painter->drawPath(secondsPath);
    //
}

void OCseconds::setValue(int value)
{
    //
    m_value = value;
    update();
    //
}

void OCseconds::setEven(bool even) { m_even = even; }
