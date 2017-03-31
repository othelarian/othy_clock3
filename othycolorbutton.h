#ifndef OTHYCOLORBUTTON_H
#define OTHYCOLORBUTTON_H

#include <QtWidgets>

class OthyColorButton : public QAbstractButton
{
    Q_OBJECT

private:
    QColor color;

public:
    explicit OthyColorButton(QWidget *parent = 0);
    void setColor(QColor newcol);
    QColor getColor();

public slots:
    void click();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

};

#endif // OTHYCOLORBUTTON_H
