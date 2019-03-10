#ifndef POINT_H
#define POINT_H

#include "mapobject.h"
#include "point_name.h"
#include "point_pic.h"



class Point : public MapObject
{
public:
    Point(QGraphicsScene *scene, QString name, QObject *parent = nullptr);

    void SetPos(QString coords);

    void Scale(qreal factor);

private:
    QPointF m_pos;
    QPointF m_geoPos;
    Point_Pic *m_pic;
    Point_Name *m_name;

};

#endif // POINT_H
