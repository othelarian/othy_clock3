#ifndef OCHOURS_H
#define OCHOURS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QtMath>

#include "ocsettings.h"

// global prototypes ####################

QPainterPath ocDrawRing(int size, int thick);

QPainterPath ocDrawArc(int size, int thick, int angle, bool sens);

// OChoursTicks class ###################

class OChoursTicks : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int value WRITE setValue)
public:
    OChoursTicks(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
private:
    OCsettings* m_settings;
    int m_value;
};

// OChoursCog class #####################

class OChoursCog : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int value WRITE setValue)
public:
    OChoursCog(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
private:
    OCsettings* m_settings;
    int m_value;
};

// OChoursBg class ######################

class OChoursBg : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int value WRITE setValue)
public:
    OChoursBg(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
private:
    OCsettings* m_settings;
    int m_value;
};

#endif // OCHOURS_H
