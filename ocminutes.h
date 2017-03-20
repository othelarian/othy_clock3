#ifndef OCMINUTES_H
#define OCMINUTES_H

#include <QQuickItem>
#include <QQuickPaintedItem>

class OCminutes : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCminutes(QQuickItem *parent = 0);
    void paint(QPainter *painter);
};

#endif // OCMINUTES_H
