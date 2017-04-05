#ifndef OCDAYS_H
#define OCDAYS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

// global prototypes ####################

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens);

// OCdaysTicks class ####################

class OCdaysTicks : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCdaysTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

// OCdaysCog class ######################

class OCdaysCog : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCdaysCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

#endif // OCDAYS_H
