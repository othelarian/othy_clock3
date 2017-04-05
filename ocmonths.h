#ifndef OCMONTHS_H
#define OCMONTHS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

// global prototypes ####################

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens);

// OCmonthsTicks class ##################

class OCmonthsTicks : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCmonthsTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

// OCmonthsCog class ####################

class OCmonthsCog : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCmonthsCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

#endif // OCMONTHS_H
