#ifndef POINT_PIC_H
#define POINT_PIC_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>



class Point_Pic : public QGraphicsPixmapItem
{
public:
    Point_Pic(QGraphicsItem *parent = nullptr);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // POINT_PIC_H
