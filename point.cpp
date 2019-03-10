#include "point.h"
#include "coordinateconverter.h"

Point::Point(QGraphicsScene *scene, QString name, QObject *parent):
    MapObject (scene, parent)
{
    m_pic = new Point_Pic();

    m_name = new Point_Name(name);
    m_name->setBrush(*m_textBrush);

    m_scene->addItem(m_pic);
    m_scene->addItem(m_name);
}

void Point::SetPos(QString coords)
{
    QStringList c = coords.split(';');
    QStringList lat = c.at(0).split(' ');
    QStringList lon = c.at(1).split(' ');
    m_geoPos.setX(lambert::GeoToDegDecimal(lon.at(0), lon.at(1), lon.at(2)));
    m_geoPos.setY(lambert::GeoToDegDecimal(lat.at(0), lat.at(1), lat.at(2)));
    lambert::GeoToScreen(m_pos, m_geoPos);
    m_pic->setPos(m_pos);
    m_name->setPos(m_pos.x()+5, m_pos.y()-15);
}

void Point::Scale(qreal factor)
{
    m_pic->setPos(m_pos*factor);
    m_name->setPos(m_pos.x()*factor+5, m_pos.y()*factor-15);
}
