#ifndef POINT_NAME_H
#define POINT_NAME_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSimpleTextItem>



class Point_Name : public QGraphicsSimpleTextItem
{
public:
    Point_Name(QString name, QGraphicsItem *parent = nullptr);

private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // POINT_NAME_H
