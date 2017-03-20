#ifndef OCSECONDS_H
#define OCSECONDS_H

#include <QPainter>
#include <QBrush>
#include <QQuickItem>
#include <QQuickPaintedItem>

class OCseconds : public QQuickPaintedItem
{
    Q_OBJECT
    //Q_PROPERTY(bool )
public:
    OCseconds(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //
    //void setScale(float scale);
    void setValue(int value);
    //
private:
    float m_scale;
    int m_value;
};

#endif // OCSECONDS_H
