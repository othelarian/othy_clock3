#ifndef OCHOURS_H
#define OCHOURS_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

class OChours : public QQuickPaintedItem
{
    Q_OBJECT
public:
    OChours(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setValue(int value);
private:
    int m_value;
    QPainterPath backcirclepath;
    QPainterPath backcogpath;
};

#endif // OCHOURS_H
