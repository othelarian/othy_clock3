#ifndef OCWEEK_H
#define OCWEEK_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

// global prototypes ####################

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens);

// OCweekTicks class ####################

class OCweekTicks : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCweekTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

// OCweekCog class ######################

class OCweekCog : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCweekCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

#endif // OCWEEK_H
