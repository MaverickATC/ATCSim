#include "target_pic.h"

Target_Pic::Target_Pic(QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
{
    this->setPixmap(QPixmap(":/img/target.png"));
    this->setOffset(-1*(this->pixmap().size().width() / 2 + 1),-1*(this->pixmap().size().height() / 2 + 1));
}

void Target_Pic::SetPos(QPointF pos)
{
    this->setPos(pos);
}

void Target_Pic::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //
    Q_UNUSED(event);
}
