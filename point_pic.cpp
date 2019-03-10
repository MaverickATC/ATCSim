#include "point_pic.h"
#include <QDebug>

Point_Pic::Point_Pic(QGraphicsItem *parent):
    QGraphicsPixmapItem (parent)
{
    this->setPixmap(QPixmap(":/img/point.png"));
    this->setOffset(-1*(this->pixmap().size().width() / 2 + 1),-1*(this->pixmap().size().height() / 2 + 1));
}

void Point_Pic::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->contains(event->pos()))
        qDebug() << "click on point";
}
