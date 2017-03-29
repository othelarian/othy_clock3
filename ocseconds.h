#ifndef OCSECONDS_H
#define OCSECONDS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

class OCseconds : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int value WRITE setValue)
    Q_PROPERTY(bool even WRITE setEven)
public:
    OCseconds(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
    void setEven(bool even);
private:
    int m_value;
    bool m_even;
};

#endif // OCSECONDS_H
