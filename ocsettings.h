#ifndef OCSETTINGS_H
#define OCSETTINGS_H

#include <QColor>
#include <QObject>

class OCsettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor bgGlobal READ getBgGlobal WRITE setBgGlobal)
public:
    static OCsettings* getInstance();
    // COLORS GETTERS ##########
    // global background getter
    QColor getBgGlobal();
    //
    // hours colors getters
    QColor getColHoursBg();
    QColor getColHoursNeedle();
    QColor getColHoursArc();
    //
    // COLORS SETTERS ##########
    // global background setter
    void setBgGlobal(QColor color);
    //
    // SIZES GETTERS ###########
    //
    // hours sizes getters
    int getSizeHoursBgDim();
    int getSizeHoursBgThick();
    int getSizeHoursNeedleDist();
    int getSizeHoursNeedleDim();
    int getSizeHoursNeedleThick();
    int getSizeHoursArcDim();
    int getSizeHoursArcThick();
    //
    // SIZES SETTERS ###########
    //
private:
    OCsettings(QObject *parent = 0);
    static OCsettings* m_instance;
    // COLORS ##################
    // global background color
    QColor m_col_bg;
    //
    // hours colors
    QColor m_col_hours_bg;
    QColor m_col_hours_needle;
    QColor m_col_hours_arc;
    // minutes colors
    //
    // seconds colors
    //
    // SIZES ###################
    //
    // hours sizes
    int m_size_hours_bg_dim;
    int m_size_hours_bg_thick;
    int m_size_hours_needle_dist;
    int m_size_hours_needle_dim;
    int m_size_hours_needle_thick;
    int m_size_hours_arc_dim;
    int m_size_hours_arc_thick;
    //
};

#endif // OCSETTINGS_H
