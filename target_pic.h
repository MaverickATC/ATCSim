#ifndef TARGET_PIC_H
#define TARGET_PIC_H

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>



class Target_Pic : public QGraphicsPixmapItem
{
public:
    Target_Pic(QGraphicsItem *parent = nullptr);

    void SetPos(QPointF pos);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // TARGET_PIC_H
