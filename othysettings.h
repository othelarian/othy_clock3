#ifndef OTHYSETTINGS_H
#define OTHYSETTINGS_H

#include "othycolorbutton.h"
#include "othykeeper.h"

#include <QtWidgets>

struct subCtrls
{
    bool extend = false;
    QString title;
    QGroupBox *activeCtrl;
    QSpinBox *startEdit;
    QSpinBox *heightEdit;
    QSpinBox *thickEdit;
    QSpinBox *offsetXEdit;
    QSpinBox *offsetYEdit;
    OthyColorButton *colorEdit;
    QComboBox *capEdit;
    //
    // TODO : for the week, days and months
    //
    QSpinBox *rotateEdit;
    QSpinBox *angleEdit;
    //
};

struct baseCtrls
{
    QString title;
    QComboBox *orderEdit;
    struct subCtrls needleCtrl;
    struct subCtrls ticksCtrl;
    struct subCtrls arcCtrl;
    struct subCtrls invarcCtrl;
};

class OthySettings : public QWidget
{
    Q_OBJECT

private:
    // SPECIAL ATTRIBUTES
    OthyKeeper* keeper;
    QString baseOrder;
    // GENERIC CONTROLS
    QSpinBox *genWidthEdit;
    QSpinBox *genHeightEdit;
    OthyColorButton *genBackColEdit;
    QComboBox *genOrder1Edit;
    QComboBox *genOrder2Edit;
    QComboBox *genOrder3Edit;
    QComboBox *genOrder4Edit;
    QComboBox *genOrder5Edit;
    QComboBox *genOrder6Edit;
    // TIME CONTROLS
    struct baseCtrls secondsCtrl;
    struct baseCtrls minutesCtrl;
    struct baseCtrls hoursCtrl;
    //
    // TODO : add other controls (week, days, months)
    //
    // METHODS
    void createBaseControls(QTabWidget *tab,baseCtrls *ctrl);
    void createSubControls(subCtrls *subCtrl);
    void createGenericControls(QBoxLayout *mainLayout);
    void createButtonsControls(QBoxLayout *mainLayout);
    void createOrderControl(QComboBox *combobox);
    QComboBox* generateBaseOrderList(int index);
    void setBaseOrderList();
    void updateBaseOrderList(int index,int box);
    //
    void ctrlShow(baseCtrls *ctrl);
    void subCtrlShow(subCtrls *subCtrl);
    //
    void writeSettings();

private slots:
    void reset();
    void apply();
    void applyAndClose();
    void updateBaseOrder1(int index);
    void updateBaseOrder2(int index);
    void updateBaseOrder3(int index);
    void updateBaseOrder4(int index);
    void updateBaseOrder5(int index);
    void updateBaseOrder6(int index);

public:
    OthySettings(QWidget *parent = 0);
    ~OthySettings();

public slots:
    void show();

};

#endif // OTHYSETTINGS_H
