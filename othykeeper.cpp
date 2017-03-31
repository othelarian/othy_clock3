#include "othykeeper.h"

OthyKeeper* OthyKeeper::m_instance = nullptr;

OthyKeeper::OthyKeeper()
{
    counter = 0;
    lastTime = 0;
    // GENERIC SETTINGS
    addSetting("winWidth",200);
    addSetting("winHeight",200);
    addSetting("winBackCol",QColor(0,0,0));
    addSetting("winOrderVisibility","smhwda");
    // SECONDS SETTINGS
    //
    // TODO : default seconds settings
    //
    //propslist.append("");
    //
    // MINUTES SETTINGS
    //
    // TODO : default minutes settings
    //
    // UPDATE THE DATA
    updatePrefs();
}

// PRIVATE METHODS #####################

void OthyKeeper::addSetting(QString key, QVariant defaut)
{
    propslist.append(key); propsdefaut.append(defaut);
}

void OthyKeeper::updatePrefs()
{
    lastTime = settings.value("lastTime",0).toInt();
    for (int i = 0;i < propslist.size(); ++i)
        properties[propslist.at(i)] = settings.value(propslist.at(i),propsdefaut.at(i));
}

QVariant OthyKeeper::getPrefs(QString key, bool defaut)
{
    if (defaut) return propsdefaut.at(propslist.indexOf(key));
    else return properties.value(key);
}

// PUBLIC METHODS ######################

OthyKeeper* OthyKeeper::getInstance()
{
    if (m_instance == nullptr) m_instance = new OthyKeeper();
    return m_instance;
}

void OthyKeeper::checkPrefs()
{
    if (counter == 10)
    {
        if (lastTime < settings.value("lastTime",0).toInt())
        {
            updatePrefs();
            lastTime = settings.value("lastTime",0).toInt();
        }
        counter = 0;
    }
    else counter++;
}

void OthyKeeper::setPrefs(QString key,QVariant value)
{
    properties[key] = value;
    settings.setValue(key,value);
    counter = 0;
}

int OthyKeeper::getPrefsInt(QString key, bool defaut)
{
    return getPrefs(key,defaut).toInt();
}

QString OthyKeeper::getPrefsString(QString key, bool defaut)
{
    return getPrefs(key,defaut).toString();
}

QColor OthyKeeper::getPrefsColor(QString key, bool defaut)
{
    return getPrefs(key,defaut).value<QColor>();
}

void OthyKeeper::updateTime()
{
    settings.setValue("lastTime",QDateTime::currentDateTime().toTime_t());
}
