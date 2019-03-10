#ifndef SECTOR_H
#define SECTOR_H

#include "mapobject.h"
#include "radarscene.h"

#include <QGraphicsPolygonItem>
#include <QObject>

class Sector : public QGraphicsPolygonItem, public MapObject
{
public:
    Sector(QString filename, MapObject::coordType coordType, RadarScene *scene, QObject *parent = nullptr);

    bool IsActive();
    void SetActive(bool active);

    void Scale(qreal factor);

private:
    bool readFile(QString filename, MapObject::coordType coordType);

    QPolygonF m_points;
    bool m_active;
};

#endif // SECTOR_H
