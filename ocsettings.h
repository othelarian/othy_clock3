#ifndef OCSETTINGS_H
#define OCSETTINGS_H

#include <QColor>
#include <QObject>
#include <QSettings>
#include <QHash>

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
    //
    // ACCESSORS ###############
    Q_INVOKABLE void setColor(QString name, QColor value, bool init);
    Q_INVOKABLE QColor getColor(QString name);
    Q_INVOKABLE void setSize(QString name, int value, bool init);
    Q_INVOKABLE int getSize(QString name);
    Q_INVOKABLE void setActive(QString name, bool value, bool init);
    Q_INVOKABLE bool getActive(QString name);
    //
private:
    OCsettings(QObject *parent = 0);
    static OCsettings* m_instance;
    //
    QSettings m_settings;
    QHash<QString,QVariant> m_default;
    QHash<QString,QVariant> m_values;
    //
    // COLORS ##################
    // global background color
    QColor m_col_bg;
    //
    // hours colors
    QColor m_col_hours_bg;
    QColor m_col_hours_needle;
    QColor m_col_hours_arc;
    QColor m_col_hours_bticks;
    QColor m_col_hours_fticks;
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
