#ifndef OCBACKGROUND_H
#define OCBACKGROUND_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
//#include <QPen>
#include <QQuickItem>
#include <QQuickPaintedItem>

class OCbackground : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OCbackground(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    //void setValue(int value);
private:
    QPainterPath m_weekpath;
};

#endif // OCBACKGROUND_H
