#include "radarview.h"

RadarView::RadarView(int w, int h, QWidget *parent) : QGraphicsView(parent)
{
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setMouseTracking(true);
    this->setGeometry(0, 0, w, h);
}
