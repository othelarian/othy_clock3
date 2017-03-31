#include "othycolorbutton.h"

OthyColorButton::OthyColorButton(QWidget *parent)
    : QAbstractButton(parent)
{
    setMinimumSize(30,20);
    connect(this,&QAbstractButton::clicked,this,&OthyColorButton::click);
}

void OthyColorButton::click()
{
    const QColor newcol = QColorDialog::getColor(color,this,"Select Color");
    if (newcol.isValid())
    {
        color.setRgb(newcol.rgb());
        update();
    }
}

void OthyColorButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(0,0,30,20,QColor(0,0,0));
    painter.fillRect(1,1,28,18,color);
}

void OthyColorButton::setColor(QColor newcol)
{
    color.setRgb(newcol.rgb());
    update();
}

QColor OthyColorButton::getColor() { return color; }
