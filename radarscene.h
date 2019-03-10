#ifndef RADARSCENE_H
#define RADARSCENE_H

#include "mapobject.h"

#include <QGraphicsScene>

class RadarScene : public QGraphicsScene
{
public:
    RadarScene(int w, int h, QObject *parent = nullptr);

    void Scale(qreal value);

    QPointF center();
    void SetCenter(QPointF newC, int scale);
    void AddMapObj(MapObject *obj);

private:
    QColor *m_backgroundColor;
    QBrush *m_backgroundBrush;
    QPointF m_center;
    QVector<MapObject*> m_map_objects;

};

#endif // RADARSCENE_H
