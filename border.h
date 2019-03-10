#ifndef BORDER_H
#define BORDER_H

#include "mapobject.h"
#include "radarscene.h"

#include <QObject>
#include <QGraphicsPolygonItem>


class Border : public QGraphicsPolygonItem, public MapObject
{
public:
    Border(QString filename, MapObject::coordType coordType, RadarScene *scene, QObject *parent = nullptr);

    void Scale(qreal factor);

private:
    bool readFile(QString filename, MapObject::coordType coordType);

    QPolygonF m_points;
};

#endif // BORDER_H
