#include "point_name.h"

#include <QCursor>

Point_Name::Point_Name(QString name, QGraphicsItem *parent):
    QGraphicsSimpleTextItem(parent)
{
    this->setText(name);
}

void Point_Name::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
    //qDebug() << "on point";
}

void Point_Name::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    if(this->contains(QPointF(event->pos().x(), event->pos().y())))
    {
       this->setCursor(QCursor(Qt::ClosedHandCursor));
    }

    Q_UNUSED(event);
}

void Point_Name::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
