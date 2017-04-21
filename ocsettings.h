#ifndef OCSETTINGS_H
#define OCSETTINGS_H

#include <QColor>
#include <QObject>
#include <QSettings>
#include <QHash>

class OCsettings : public QObject
{
    Q_OBJECT
public:
    static OCsettings* getInstance();
    Q_INVOKABLE void setSetting(QString name, QVariant value);
    Q_INVOKABLE void resetSetting(QString name);
    Q_INVOKABLE QColor getColor(QString name, bool def = false);
    Q_INVOKABLE int getSize(QString name, bool def = false);
    Q_INVOKABLE bool getActive(QString name, bool def = false);
private:
    OCsettings(QObject *parent = 0);
    void initSeconds();
    void initMinutes();
    void initHours();
    void initWeek();
    void initDays();
    void initMonths();
    static OCsettings* m_instance;
    QSettings m_settings;
    QHash<QString,QVariant> m_default;
    QHash<QString,QVariant> m_values;
};

#endif // OCSETTINGS_H
