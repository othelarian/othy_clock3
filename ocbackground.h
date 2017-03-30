#ifndef OCBACKGROUND_H
#define OCBACKGROUND_H

#include <QBrush>
#include <QPainter>
#include <QPainterPath>
#include <QQuickItem>
#include <QQuickPaintedItem>

#include "ocsettings.h"

class OCbackground : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(int hoursValue WRITE setHoursValue)
public:
    OCbackground(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void setHoursValue(int value);
private:
    OCsettings* m_settings;
    int m_hours_value;
    //
};

#endif // OCBACKGROUND_H
