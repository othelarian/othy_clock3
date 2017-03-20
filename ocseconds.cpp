#include "ocseconds.h"

OCseconds::OCseconds(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    //
    qInfo() << "init width: " << width();
    //
}

void OCseconds::paint(QPainter *painter)
{
    //
    qInfo() << "painted width: " << width();
    //
    QBrush brush(QColor("#0045ff"));
    painter->setBrush(brush);
    painter->setPen(Qt::NoPen);
    //painter->setRenderHint(QPainter::Antialiasing);
    //
    painter->drawRoundedRect(0,0,30,30,10,10);
    //
}

void OCseconds::setValue(int value)
{
    m_value = value;
}
