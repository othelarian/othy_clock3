#ifndef OCMINUTES_H
#define OCMINUTES_H

#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

// OCminutesTicks class #################

class OCminutesTicks : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCminutesTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
};

// OCminutesCog class ###################

class OCminutesCog : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCminutesCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
};

#endif // OCMINUTES_H
