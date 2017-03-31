#ifndef OTHYCLOCK_H
#define OTHYCLOCK_H

#include "othykeeper.h"

#include <QtWidgets>

class OthyClock : public QWidget
{
    Q_OBJECT

private:
    int winWidth;
    int winHeight;
    OthyKeeper* keeper;

public:
    OthyClock(QWidget *parent = 0);
    ~OthyClock();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // OTHYCLOCK_H
