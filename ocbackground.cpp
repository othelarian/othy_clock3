#include "ocbackground.h"

#include <QDebug>

OCbackground::OCbackground(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    //
    m_weekpath.arcTo(QRectF(QPointF(0,0),QPointF(200,200)),30,160);
    //
}

void OCbackground::paint(QPainter *painter)
{
    //
    int dim = qMax(width(),height());
    QPoint center(width()/2,height()/2);
    //int centerx = w
    //
    qInfo() << "bg dim: " << dim;
    //
    painter->translate(center);
    //
    QBrush brush(QColor("#ff0000"));
    painter->setBrush(brush);
    //
    //painter->drawPath(m_weekpath);
    //
}


