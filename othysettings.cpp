#include "othysettings.h"

// HELPER FUNCTIONS ####################

int convertBaseOrder(QChar c)
{
    if (c == 's') return 0;
    if (c == 'm') return 1;
    if (c == 'h') return 2;
    if (c == 'w') return 3;
    if (c == 'd') return 4;
    if (c == 'a') return 5;
}

QChar revertBaseOrder(int i)
{
    switch (i) {
    case 0: return 's';
    case 1: return 'm';
    case 2: return 'h';
    case 3: return 'w';
    case 4: return 'd';
    case 5: return 'a';
    default: return 'x';
    }
}

int convertCtrlOrder(QChar c)
{
    if (c == 'n') return 0;
    if (c == 't') return 1;
    if (c == 'a') return 2;
    if (c == 'i') return 3;
    return -1;
}

// CONSTRUCTOR & DESTRUCTOR ############

OthySettings::OthySettings(QWidget *parent)
    : QWidget(parent)
{
    // SET SETTING WINDOW SPECS
    setWindowTitle("Othy Clock - Settings");
    setWindowModality(Qt::ApplicationModal);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QTabWidget *tab = new QTabWidget();
    // GENERIC CONTROLS
    createGenericControls(mainLayout);
    // SECONDS CONTROLS
    secondsCtrl.title = "Seconds";
    createBaseControls(tab,&secondsCtrl);
    // MINUTES CONTROLS
    minutesCtrl.title = "Minutes";
    createBaseControls(tab,&minutesCtrl);
    // HOURS CONTROLS
    hoursCtrl.title = "Hours";
    createBaseControls(tab,&hoursCtrl);
    // WEEK CONTROLS
    //
    // TODO : create week controls
    //
    //createWeekControls(mainLayout);
    //
    // DAYS CONTROLS
    //
    // TODO : create days controls
    //
    //createDaysControls(mainLayout);
    //
    // MONTHS CONTROLS
    //
    // TODO : create months controls
    //
    //createMonthsControls(mainLayout);
    //
    // INSERT TAB
    mainLayout->addWidget(tab);
    // CONTROL BUTTONS
    createButtonsControls(mainLayout);
    // LAST CONFIG ELEMENT
    //
    keeper = OthyKeeper::getInstance();
    //
    hide();
}

OthySettings::~OthySettings() {}

// SLOTS ###############################

void OthySettings::show()
{
    // GENERIC SETTINGS
    genWidthEdit->setValue(keeper->getPrefsInt("winWidth"));
    genHeightEdit->setValue(keeper->getPrefsInt("winHeight"));
    genBackColEdit->setColor(keeper->getPrefsColor("winBackCol"));
    baseOrder = keeper->getPrefsString("winOrderVisibility");
    setBaseOrderList();
    // SECONDS SETTINGS
    //
    // TODO : check for needle active
    //
    //
    //
    // TODO : check for ticks active
    //
    // TODO : check for arc active
    //
    // TODO : check for invarc active
    //
    //
    // MINUTES SETTINGS
    //
    //
    // SHOW THE SETTINGS WINDOW
    QWidget::show();
}

void OthySettings::reset()
{
    // GENERIC CONTROLS
    genWidthEdit->setValue(keeper->getPrefsInt("winWidth",true));
    genHeightEdit->setValue(keeper->getPrefsInt("winHeight",true));
    genBackColEdit->setColor(keeper->getPrefsColor("winBackCol",true));
    baseOrder = keeper->getPrefsString("winOrderVisibility",true);
    setBaseOrderList();
    // SECONDS CONTROLS
    //
    // TODO : reset seconds controls
    //
}

void OthySettings::apply() { writeSettings(); }

void OthySettings::applyAndClose() { writeSettings(); hide(); }

void OthySettings::updateBaseOrder1(int index) { updateBaseOrderList(index,0); }

void OthySettings::updateBaseOrder2(int index) { updateBaseOrderList(index,1); }

void OthySettings::updateBaseOrder3(int index) { updateBaseOrderList(index,2); }

void OthySettings::updateBaseOrder4(int index) { updateBaseOrderList(index,3); }

void OthySettings::updateBaseOrder5(int index) { updateBaseOrderList(index,4); }

void OthySettings::updateBaseOrder6(int index) { updateBaseOrderList(index,5); }

// METHODS #############################

void OthySettings::createBaseControls(QTabWidget *tab,baseCtrls *ctrl)
{
    // LABELS
    QLabel *orderLabel = new QLabel("Visibility order:");
    // COMBOBOXES
    ctrl->orderEdit = new QComboBox();
    createOrderControl(ctrl->orderEdit);
    // LAYOUTS
    QHBoxLayout *orderLayout = new QHBoxLayout();
    QGroupBox *baseCtrl = new QGroupBox();//ctrl->title+" controls");
    baseCtrl->setFlat(true);
    QGridLayout *baseLayout = new QGridLayout();
    // COMPOSING
    // -- needle
    ctrl->needleCtrl.title = "Needle";
    createSubControls(&ctrl->needleCtrl);
    baseLayout->addWidget(ctrl->needleCtrl.activeCtrl,0,0);
    // -- ticks
    ctrl->ticksCtrl.title = "Ticks";
    createSubControls(&ctrl->ticksCtrl);
    baseLayout->addWidget(ctrl->ticksCtrl.activeCtrl,0,1);
    // -- arc
    ctrl->arcCtrl.title = "Arc";
    createSubControls(&ctrl->arcCtrl);
    baseLayout->addWidget(ctrl->arcCtrl.activeCtrl,1,0);
    // -- inverted arc
    ctrl->invarcCtrl.title = "Inverted arc";
    createSubControls(&ctrl->invarcCtrl);
    baseLayout->addWidget(ctrl->invarcCtrl.activeCtrl,1,1);
    // -- other
    //
    // TODO : don't forget the case of the extended (week,days and months)
    //
    orderLayout->addWidget(orderLabel);
    orderLayout->addWidget(ctrl->orderEdit);
    baseLayout->addLayout(orderLayout,2,0,1,2);
    baseCtrl->setLayout(baseLayout);
    tab->addTab(baseCtrl,ctrl->title);
}

void OthySettings::createSubControls(subCtrls *subCtrl)
{
    // LABELS
    QLabel *startLabel = new QLabel("Start:");
    QLabel *heightLabel = new QLabel("Height:");
    QLabel *thickLabel = new QLabel("Thickness:");
    QLabel *offsetLabel = new QLabel("Offset (X Y):");
    QLabel *colorLabel = new QLabel("Color:");
    QLabel *capLabel = new QLabel("Cap:");
    // SPINBOXES
    subCtrl->startEdit = new QSpinBox();
    subCtrl->heightEdit = new QSpinBox();
    subCtrl->heightEdit->setMinimum(1);
    subCtrl->thickEdit = new QSpinBox();
    subCtrl->thickEdit->setMinimum(1);
    subCtrl->offsetXEdit = new QSpinBox();
    subCtrl->offsetYEdit = new QSpinBox();
    // COLOR
    subCtrl->colorEdit = new OthyColorButton();
    // COMBOBOX
    //
    // TODO : cap selection
    //
    subCtrl->capEdit = new QComboBox();
    //
    subCtrl->capEdit->addItem("Flat",0);
    subCtrl->capEdit->addItem("Square",1);
    subCtrl->capEdit->addItem("Round",2);
    //
    // LAYOUTS
    QHBoxLayout *offsetLayout = new QHBoxLayout();
    offsetLayout->addWidget(subCtrl->offsetXEdit);
    offsetLayout->addWidget(subCtrl->offsetYEdit);
    subCtrl->activeCtrl = new QGroupBox(subCtrl->title);
    subCtrl->activeCtrl->setCheckable(true);
    QGridLayout *subLayout = new QGridLayout();
    // COMPOSING
    subLayout->addWidget(startLabel,0,0);
    subLayout->addWidget(subCtrl->startEdit,0,1);
    subLayout->addWidget(heightLabel,0,2);
    subLayout->addWidget(subCtrl->heightEdit,0,3);
    subLayout->addWidget(capLabel,0,4);
    subLayout->addWidget(subCtrl->capEdit,0,5);
    subLayout->addWidget(thickLabel,1,0);
    subLayout->addWidget(subCtrl->thickEdit,1,1);
    subLayout->addWidget(colorLabel,1,2);
    subLayout->addWidget(subCtrl->colorEdit,1,3);
    subLayout->addWidget(offsetLabel,1,4);
    subLayout->addLayout(offsetLayout,1,5);
    subCtrl->activeCtrl->setLayout(subLayout);
}

void OthySettings::createGenericControls(QBoxLayout *mainLayout)
{
    // LABELS
    QLabel *genWidthLabel = new QLabel("Window width:");
    QLabel *genHeightLabel = new QLabel("Window height:");
    QLabel *genBackColLabel = new QLabel("Background color:");
    QLabel *genOrderLabel = new QLabel("Visiblity order:");
    QLabel *genOrder1Label = new QLabel("1:");
    QLabel *genOrder2Label = new QLabel("2:");
    QLabel *genOrder3Label = new QLabel("3:");
    QLabel *genOrder4Label = new QLabel("4:");
    QLabel *genOrder5Label = new QLabel("5:");
    QLabel *genOrder6Label = new QLabel("6:");
    // SPINBOXES
    genWidthEdit = new QSpinBox();
    genWidthEdit->setRange(200,1500);
    genHeightEdit = new QSpinBox();
    genHeightEdit->setRange(200,1000);
    // COLOR SELECTOR
    genBackColEdit = new OthyColorButton();
    // COMBOBOXES
    genOrder1Edit = generateBaseOrderList(0);
    genOrder2Edit = generateBaseOrderList(1);
    genOrder3Edit = generateBaseOrderList(2);
    genOrder4Edit = generateBaseOrderList(3);
    genOrder5Edit = generateBaseOrderList(4);
    genOrder6Edit = generateBaseOrderList(5);
    // LAYOUTS
    QHBoxLayout *firstLine = new QHBoxLayout();
    QHBoxLayout *sndLine = new QHBoxLayout();
    QGroupBox *genericCtrl = new QGroupBox("Basic controls:");
    QVBoxLayout *genericLayout = new QVBoxLayout();
    // COMPOSING
    firstLine->addWidget(genWidthLabel);
    firstLine->addWidget(genWidthEdit);
    firstLine->addWidget(genHeightLabel);
    firstLine->addWidget(genHeightEdit);
    firstLine->addWidget(genBackColLabel);
    firstLine->addWidget(genBackColEdit);
    firstLine->addStretch();
    sndLine->addWidget(genOrderLabel);
    sndLine->addWidget(genOrder1Label);
    sndLine->addWidget(genOrder1Edit);
    sndLine->addWidget(genOrder2Label);
    sndLine->addWidget(genOrder2Edit);
    sndLine->addWidget(genOrder3Label);
    sndLine->addWidget(genOrder3Edit);
    sndLine->addWidget(genOrder4Label);
    sndLine->addWidget(genOrder4Edit);
    sndLine->addWidget(genOrder5Label);
    sndLine->addWidget(genOrder5Edit);
    sndLine->addWidget(genOrder6Label);
    sndLine->addWidget(genOrder6Edit);
    sndLine->addStretch();
    genericLayout->addLayout(firstLine);
    genericLayout->addLayout(sndLine);
    genericCtrl->setLayout(genericLayout);
    mainLayout->addWidget(genericCtrl);
}

void OthySettings::createButtonsControls(QBoxLayout *mainLayout)
{
    QPushButton *defaultBtn = new QPushButton("&Default");
    connect(defaultBtn,&QPushButton::clicked,this,&OthySettings::reset);
    QPushButton *cancelBtn = new QPushButton("&Cancel");
    connect(cancelBtn,&QPushButton::clicked,this,&QWidget::close);
    QPushButton *applyBtn = new QPushButton("&Apply");
    connect(applyBtn,&QPushButton::clicked,this,&OthySettings::apply);
    QPushButton *okBtn = new QPushButton("&OK");
    connect(okBtn,&QPushButton::clicked,this,&OthySettings::applyAndClose);
    QHBoxLayout *controlsLayout = new QHBoxLayout();
    controlsLayout->addStretch();
    controlsLayout->addWidget(defaultBtn);
    controlsLayout->addWidget(cancelBtn);
    controlsLayout->addWidget(applyBtn);
    controlsLayout->addWidget(okBtn);
    mainLayout->addLayout(controlsLayout);
}

void OthySettings::createOrderControl(QComboBox *combobox)
{
    combobox->addItem("1.Needle - 2.Ticks - 3.Arc - 4.Inverted Arc","ntai");
    combobox->addItem("1.Needle - 2.Ticks - 3.Inverted Arc - 4.Arc","ntia");
    combobox->addItem("1.Needle - 2.Arc - 3.Ticks - 4.Inverted Arc","nati");
    combobox->addItem("1.Needle - 2.Arc - 3.Inverted Arc - 4.Ticks","nait");
    combobox->addItem("1.Needle - 2.Inverted Arc - 3.Ticks - 4.Arc","nita");
    combobox->addItem("1.Needle - 2.Inverted Arc - 3.Arc - 4.Ticks","niat");
    combobox->addItem("1.Ticks - 2.Needle - 3.Arc - 4.Inverted Arc","tnai");
    combobox->addItem("1.Ticks - 2.Needle - 3.Inverted Arc - 4.Arc","tnia");
    combobox->addItem("1.Ticks - 2.Arc - 3.Needle - 4.Inverted Arc","tani");
    combobox->addItem("1.Ticks - 2.Arc - 3.Inverted Arc - 4.Needle","tain");
    combobox->addItem("1.Ticks - 2.Inverted Arc - 3.Needle - 4.Arc","tina");
    combobox->addItem("1.Ticks - 2.Inverted Arc - 3.Arc - 4.Needle","tian");
    combobox->addItem("1.Arc - 2.Needle - 3.Ticks - 4.Inverted Arc","anti");
    combobox->addItem("1.Arc - 2.Needle - 3.Inverted Arc - 4.Ticks","anit");
    combobox->addItem("1.Arc - 2.Ticks - 3.Needle - 4.Inverted Arc","atni");
    combobox->addItem("1.Arc - 2.Ticks - 3.Inverted Arc - 4.Needle","atin");
    combobox->addItem("1.Arc - 2.Inverted Arc - 3.Needle - 4.Ticks","aint");
    combobox->addItem("1.Arc - 2.Inverted Arc - 3.Ticks - 4.Needle","aitn");
    combobox->addItem("1.Inverted Arc - 2.Needle - 3.Ticks - 4.Arc","inta");
    combobox->addItem("1.Inverted Arc - 2.Needle - 3.Arc - 4.Ticks","inat");
    combobox->addItem("1.Inverted Arc - 2.Ticks - 3.Needle - 4.Arc","itna");
    combobox->addItem("1.Inverted Arc - 2.Ticks - 3.Arc - 4.Needle","itan");
    combobox->addItem("1.Inverted Arc - 2.Arc - 3.Needle - 4.Ticks","iant");
    combobox->addItem("1.Inverted Arc - 2.Arc - 3.Ticks - 4.Needle","iatn");
}

QComboBox* OthySettings::generateBaseOrderList(int index)
{
    QComboBox *orderBox = new QComboBox();
    switch (index)
    {
    case 0:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder1(int)));
        break;
    case 1:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder2(int)));
        break;
    case 2:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder3(int)));
        break;
    case 3:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder4(int)));
        break;
    case 4:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder5(int)));
        break;
    case 5:
        connect(orderBox,SIGNAL(activated(int)),this,SLOT(updateBaseOrder6(int)));
        break;
    }
    orderBox->addItem("Seconds","s");
    orderBox->addItem("Minutes","m");
    orderBox->addItem("Hours","h");
    orderBox->addItem("Week","w");
    orderBox->addItem("Days","d");
    orderBox->addItem("Months","a");
    return orderBox;
}

void OthySettings::setBaseOrderList()
{
    genOrder1Edit->setCurrentIndex(convertBaseOrder(baseOrder[0]));
    genOrder2Edit->setCurrentIndex(convertBaseOrder(baseOrder[1]));
    genOrder3Edit->setCurrentIndex(convertBaseOrder(baseOrder[2]));
    genOrder4Edit->setCurrentIndex(convertBaseOrder(baseOrder[3]));
    genOrder5Edit->setCurrentIndex(convertBaseOrder(baseOrder[4]));
    genOrder6Edit->setCurrentIndex(convertBaseOrder(baseOrder[5]));
}

void OthySettings::updateBaseOrderList(int index,int box)
{
    baseOrder.remove(revertBaseOrder(index));
    baseOrder.insert(box,revertBaseOrder(index));
    setBaseOrderList();
}

void OthySettings::ctrlShow(baseCtrls *ctrl)
{
    //
    //
}

void OthySettings::subCtrlShow(subCtrls *subCtrl)
{
    //
    //
}

void OthySettings::writeSettings()
{
    // GENERIC SETTINGS
    keeper->setPrefs("winWidth",genWidthEdit->value());
    keeper->setPrefs("winHeight",genHeightEdit->value());
    keeper->setPrefs("winBackCol",genBackColEdit->getColor());
    keeper->setPrefs("winOrderVisibility",baseOrder);
    // SECONDS SETTINGS
    //
    // TODO : save seconds settings
    //
    // TODO : save minutes settings
    //
    // TODO : save hours settings
    //
    // TODO : save week settings
    //
    // TODO : save days settings
    //
    // TODO : save months settings
    //
    // END THE WRITING
    keeper->updateTime();
}
