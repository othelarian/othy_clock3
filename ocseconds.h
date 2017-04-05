#ifndef OCSECONDS_H
#define OCSECONDS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

// global prototypes ####################

QPainterPath ocDrawRing(int size, int thick);

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens);

// OCsecondsTicks class #################

class OCsecondsTicks : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCsecondsTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
private:
    //
    //
};

// OCsecondsCog class ###################

class OCsecondsCog : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int value WRITE setValue)
    Q_PROPERTY(bool even WRITE setEven)
public:
    OCsecondsCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
    void setEven(bool even);
private:
    int m_value;
    bool m_even;
};

#endif // OCSECONDS_H
