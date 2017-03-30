#include "ocseconds.h"

OCsecondsCog::OCsecondsCog(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_value = 0;
    m_even = true;
}

void OCsecondsCog::paint(QPainter *painter)
{
    if (m_value == 0 && m_even) return;
    int dim = qMax(width(),height());
    //
    // TODO : determine the size
    //
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
        //secondsPath.addEllipse();
        //
    }
    else {
        //
        int arc = 6*m_value;
        //
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
    secondsPath.arcTo(QRectF(-80,-80,200,200),90,-arc);
    //
    secondsPath.arcTo(QRectF(-70,-70,180,180),90-arc,arc);
    //
    //
    painter->drawPath(secondsPath);
    //
}

void OCsecondsCog::setValue(int value)
{
    //
    m_value = value;
    update();
    //
}

void OCsecondsCog::setEven(bool even) { m_even = even; }
