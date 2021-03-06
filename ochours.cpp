#include "ochours.h"

// OChoursTicks methods #################

OChoursTicks::OChoursTicks(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OChoursTicks::paint(QPainter *painter)
{
    if (m_settings->getActive("active_hours_fticks") || m_settings->getActive("ative_hours_bticks")) {
        // set basic parameters
        int dim = qMin(width(),height());
        double scale = dim/300.0;
        QPointF center(width()/2,height()/2);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->translate(center);
        painter->setPen(Qt::NoPen);
        // specific parameters
        int bdist = int(m_settings->getSize("size_hours_bticks_dist")*scale);
        int bsize = int(m_settings->getSize("size_hours_bticks_dim")*scale);
        int bthick = int(m_settings->getSize("size_hours_bticks_thick")*scale);
        int fdist = int(m_settings->getSize("size_hours_fticks_dist")*scale);
        int fsize = int(m_settings->getSize("size_hours_fticks_dim")*scale);
        int fthick = int(m_settings->getSize("size_hours_fticks_thick")*scale);
        // painting ticks
        painter->rotate(-90);
        for (int i=0;i<12;i++) {
            // draw the back ticks
            if (m_settings->getActive("active_hours_bticks") && (!m_settings->getActive("active_hours_bticks_tail") || (m_value < 12 && i > m_value) || (m_value > 12 && i < m_value%12 && i != 12 && i != 0))) {
                painter->save();
                painter->setBrush(QBrush(m_settings->getColor("col_hours_bticks")));
                painter->translate(bdist,0);
                painter->drawRect(-bsize/2,-bthick/2,bsize,bthick);
                painter->restore();
            }
            // draw the front ticks
            if (m_settings->getActive("active_hours_fticks") && ((i == m_value%12) || (m_settings->getActive("active_hours_fticks_tail") && ((i == 0) || (m_value == 12) || (m_value < 12 && i < m_value) || (m_value > 12 && i > m_value%12))))) {
                painter->save();
                painter->setBrush(QBrush(m_settings->getColor("col_hours_fticks")));
                painter->translate(fdist,0);
                painter->drawRect(-fsize/2,-fthick/2,fsize,fthick);
                painter->restore();
            }
            // rotate
            painter->rotate(30);
        }
    }
}

void OChoursTicks::setValue(int value) { m_value = value; update(); }

// OChoursCog methods ###################

OChoursCog::OChoursCog(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OChoursCog::paint(QPainter *painter)
{
    if (m_settings->getActive("active_hours_arc") || m_settings->getActive("active_hours_needle")) {
        // set basic parameters
        int dim = qMin(width(),height());
        double scale = dim/300.0;
        QPointF center(width()/2,height()/2);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->translate(center);
        painter->setPen(Qt::NoPen);
        int size = 0, thick = 0;
        int arc = 30*((m_value < 12)? m_value : m_value-12);
        // painting arc
        if (m_settings->getActive("active_hours_arc") && m_value != 0) {
            painter->save();
            size = int(m_settings->getSize("size_hours_arc_dim")*scale);
            thick = int(m_settings->getSize("size_hours_arc_thick")*scale);
            painter->setBrush(QBrush(m_settings->getColor("col_hours_arc")));
            if (m_value == 12) painter->drawPath(ocDrawRing(size,thick));
            else painter->drawPath(ocDrawArc(size,thick,arc,m_value < 12));
            painter->restore();
        }
        // painting cog
        if (m_settings->getActive("active_hours_needle")) {
            painter->save();
            size = int(m_settings->getSize("size_hours_needle_dim")*scale);
            thick = int(m_settings->getSize("size_hours_needle_thick")*scale);
            int dist = int(m_settings->getSize("size_hours_needle_dist")*scale);
            int dx = int(qCos(qDegreesToRadians(double(arc-90)))*dist);
            int dy = int(qSin(qDegreesToRadians(double(arc-90)))*dist);
            painter->translate(dx,dy);
            painter->setBrush(QBrush(m_settings->getColor("col_hours_needle")));
            painter->drawPath(ocDrawRing(size,thick));
            painter->restore();
        }
    }
}

void OChoursCog::setValue(int value) { m_value = value; update(); }

// OChoursBg methods ####################

OChoursBg::OChoursBg(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    m_settings = OCsettings::getInstance();
}

void OChoursBg::paint(QPainter *painter)
{
    if (m_settings->getActive("active_hours_bg") && (!m_settings->getActive("active_hours_bg_tail") || m_value != 12)) {
        // set basic parameters
        int dim = qMin(width(),height());
        double scale = dim/300.0;
        QPointF center(width()/2,height()/2);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->translate(center);
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(m_settings->getColor("col_hours_bg")));
        int size = int(m_settings->getSize("size_hours_bg_dim")*scale);
        int thick = int(m_settings->getSize("size_hours_bg_thick")*scale);
        // if the background is a full circle
        if (!m_settings->getActive("active_hours_bg_tail") || m_value == 0) {
            painter->drawPath(ocDrawRing(size,thick));
        }
        // otherwise
        else {
            int arc = 30*((m_value < 12)? m_value : m_value-12);
            painter->drawPath(ocDrawArc(size,thick,arc,m_value > 12));
        }
    }
}

void OChoursBg::setValue(int value) { m_value = value; update(); }
