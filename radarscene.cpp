#include "radarscene.h"
#include "coordinateconverter.h"

#include <QGraphicsItem>

//494708 0251222 ---default center

RadarScene::RadarScene(int w, int h, QObject *parent) : QGraphicsScene(parent)
{
    m_backgroundColor = new QColor(Qt::darkYellow);
    m_backgroundBrush = new QBrush(*m_backgroundColor, Qt::SolidPattern);
    this->setBackgroundBrush(*m_backgroundBrush);

    QPointF c(lambert::GeoToDegDecimal("49 47 08;025 12 22", ';', ' '));
//    c.setX(lambert::GeoToDegDecimal("49", "47", "08"));
//    c.setY(lambert::GeoToDegDecimal("025", "12", "22"));
    lambert::GeoToScreen(m_center, c);
    QRectF sr(0, 0, w, h);
    sr.moveCenter(m_center);
    this->setSceneRect(sr);
}

void RadarScene::Scale(qreal value)
{
    QRectF sr(this->sceneRect());
    sr.moveCenter(m_center * value);
    this->setSceneRect(sr);

    for(int i = 0; i < m_map_objects.size(); i++)
    {
        m_map_objects.value(i)->Scale(value);
    }

//    for(int i = 0; i < this->items().size(); i++)
//    {
//        this->items().at(i)->setScale(value);
//    }
}

QPointF RadarScene::center()
{
    return m_center;
}

void RadarScene::SetCenter(QPointF newC, int scale)
{
    m_center = newC / scale;

    QRectF sr(this->sceneRect());
    sr.moveCenter(m_center * scale);
    this->setSceneRect(sr);
}

void RadarScene::AddMapObj(MapObject *obj)
{
    m_map_objects.push_back(obj);
}
