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
    Q_INVOKABLE QColor getColor(QString name);
    Q_INVOKABLE int getSize(QString name);
    Q_INVOKABLE bool getActive(QString name);
private:
    OCsettings(QObject *parent = 0);
    static OCsettings* m_instance;
    QSettings m_settings;
    QHash<QString,QVariant> m_default;
    QHash<QString,QVariant> m_values;
};

#endif // OCSETTINGS_H
