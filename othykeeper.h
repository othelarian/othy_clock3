#ifndef OTHYKEEPER_H
#define OTHYKEEPER_H

#include <QtWidgets>
#include <QHash>
#include <QVector>

class OthyKeeper
{
private:
    // CONSTANT
    QVector<QString> propslist;
    QVector<QVariant> propsdefaut;
    // UNIQUE INSTANCE
    OthyKeeper();
    static OthyKeeper* m_instance;
    QSettings settings;
    int counter;
    int lastTime;
    QHash<QString,QVariant> properties;
    // PRIVATE METHODS
    void addSetting(QString key,QVariant defaut);
    void updatePrefs();
    QVariant getPrefs(QString key,bool defaut = false);

public:
    static OthyKeeper* getInstance();
    void checkPrefs();
    void setPrefs(QString key,QVariant value);
    int getPrefsInt(QString key,bool defaut = false);
    QString getPrefsString(QString key,bool defaut = false);
    QColor getPrefsColor(QString key,bool defaut = false);
    void updateTime();
};

#endif // OTHYKEEPER_H
