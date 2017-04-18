#include "ocsettings.h"

#include <QDebug>

// initialize OCsettings instance ############

OCsettings* OCsettings::m_instance = nullptr;

OCsettings::OCsettings(QObject *parent) : QObject(parent)
{
    // INIT COLORS ########
    // global background color
    m_default["col_bg"] = QColor::fromRgbF(0,0,0);
    // months colors
    //
    // days colors
    //
    // week colors
    //
    // hours colors
    m_default["col_hours_fticks"] = QColor::fromRgbF(1,0.4,0.01);
    m_default["col_hours_bticks"] = QColor::fromRgbF(0.8,0.8,0.8);
    m_default["col_hours_bg"] = QColor::fromRgbF(0.3,0.3,0.3);
    m_default["col_hours_arc"] = QColor::fromRgbF(0,0.5,1);
    m_default["col_hours_needle"] = QColor::fromRgbF(1,0.4,0.01);
    // minutes colors
    //
    // seconds colors
    //
    // INIT SIZES #########
    // months sizes
    //
    // days sizes
    //
    // week sizes
    //
    // hours sizes
    //
    m_default["size_hours_fticks_dim"] = 0;
    m_default["size_hours_fticks_thick"] = 0;
    m_default["size_hours_fticks_dist"] = 0;
    m_default["size_hours_bticks_dim"] = 0;
    m_default["size_hours_bticks_thick"] = 0;
    m_default["size_hours_bticks_dist"] = 0;
    //
    m_default["size_hours_bg_dim"] = 197;
    m_default["size_hours_bg_thick"] = 8;
    m_default["size_hours_arc_dim"] = 200;
    m_default["size_hours_arc_thick"] = 15;
    m_default["size_hours_needle_dim"] = 32;
    m_default["size_hours_needle_thick"] = 10;
    m_default["size_hours_needle_dist"] = 92;
    // minutes sizes
    //
    // seconds sizes
    //
    // INIT ACTIVE ########
    // months actives
    //
    // days actives
    //
    // week actives
    //
    // hours actives
    //
    m_default["active_hours_bg"] = false;
    //
    m_default["active_hours_arc"] = true;
    m_default["active_hours_needle"] = true;
    //
    m_default["active_hours_fticks"] = true;
    m_default["active_hours_bticks"] = true;
    //
    // minutes actives
    //
    // seconds actives
    //
    // SET PROPERTIES #####
    QHashIterator<QString,QVariant> i(m_default);
    while (i.hasNext()) {
        i.next();
        m_values.insert(i.key(),m_settings.value(i.key(),i.value()));
    }
}

OCsettings* OCsettings::getInstance()
{
    if (m_instance == nullptr) m_instance = new OCsettings();
    return m_instance;
}

// ACCESSORS #################################

void OCsettings::setSetting(QString name, QVariant value)
{
    m_values[name] = value;
    m_settings.setValue(name,value);
}

void OCsettings::resetSetting(QString name)
{
    m_values[name] = m_default[name];
    m_settings.remove(name);
}

QColor OCsettings::getColor(QString name) { return m_values[name].value<QColor>(); }

int OCsettings::getSize(QString name) { return m_values[name].toInt(); }

bool OCsettings::getActive(QString name) { return m_values[name].toBool(); }
