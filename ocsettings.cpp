#include "ocsettings.h"

// initialize OCsettings instance ############

OCsettings* OCsettings::m_instance = nullptr;

OCsettings::OCsettings(QObject *parent) : QObject(parent)
{
    // INIT COLORS ########
    // global background color
    m_col_bg.setRgb(0,0,0);
    // months colors
    //
    // hours colors
    m_col_hours_bg.setRgb(60,60,60);
    m_col_hours_needle.setRgb(255,100,10);
    m_col_hours_arc.setRgb(0,125,255);
    m_col_hours_bticks.setRgb(200,200,200,100);
    m_col_hours_fticks.setRgb(255,100,10,150);
    // minutes colors
    //
    // seconds colors
    //
    // INIT SIZES #########
    //
    // hours sizes
    m_size_hours_bg_dim = 197;
    m_size_hours_bg_thick = 8;
    m_size_hours_needle_dist = 92;
    m_size_hours_needle_dim = 32;
    m_size_hours_needle_thick = 10;
    m_size_hours_arc_dim = 200;
    m_size_hours_arc_thick = 15;
    //
}

OCsettings* OCsettings::getInstance()
{
    if (m_instance == nullptr) m_instance = new OCsettings();
    return m_instance;
}

// COLORS GETTERS ############################

// global background getter
QColor OCsettings::getBgGlobal() { return m_col_bg; }
// week colors getters
// hours colors getters
QColor OCsettings::getColHoursBg() { return m_col_hours_bg; }
QColor OCsettings::getColHoursNeedle() { return m_col_hours_needle; }
QColor OCsettings::getColHoursArc() { return m_col_hours_arc; }

// SIZES GETTERS #############################

// hours size getters
int OCsettings::getSizeHoursBgDim() { return m_size_hours_bg_dim; }
int OCsettings::getSizeHoursBgThick() { return m_size_hours_bg_thick; }
int OCsettings::getSizeHoursNeedleDist() { return m_size_hours_needle_dist; }
int OCsettings::getSizeHoursNeedleDim() { return m_size_hours_needle_dim; }
int OCsettings::getSizeHoursNeedleThick() { return m_size_hours_needle_thick; }
int OCsettings::getSizeHoursArcDim() { return m_size_hours_arc_dim; }
int OCsettings::getSizeHoursArcThick() { return m_size_hours_arc_thick; }

// COLORS SETTERS ############################

void OCsettings::setBgGlobal(QColor color) {
    //
    // TODO : set in local storage
    //
    m_col_bg = color;
    //
}

// SIZES SETTERS #############################
