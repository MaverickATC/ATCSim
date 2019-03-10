#include "sector.h"
#include "coordinateconverter.h"
#include <QFile>

Sector::Sector(QString filename, MapObject::coordType coordType, RadarScene *scene, QObject *parent):
        MapObject(scene, parent), m_active(false)
{
    readFile(filename, coordType);

    this->setPen(*m_pen);

    m_sectorBrush->setStyle(Qt::NoBrush);
    this->setBrush(*m_sectorBrush);
    //this->brush().setStyle(Qt::NoBrush);

    m_scene->addItem(this);
}

bool Sector::IsActive()
{
    return m_active;
}

void Sector::SetActive(bool active)
{
    m_active = active;
    if(active)
    {
        m_sectorBrush->setStyle(Qt::SolidPattern);
        this->setBrush(*m_sectorBrush);
    }
    else
    {
        m_sectorBrush->setStyle(Qt::NoBrush);
        this->setBrush(*m_sectorBrush);
    }

}

void Sector::Scale(qreal factor)
{
    this->setScale(factor);
}

bool Sector::readFile(QString filename, MapObject::coordType coordType)
{
    QFile file(filename);
    QString file_line;


    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(file.isOpen())
    {
        while(!file.atEnd())
        {
            file_line = file.readLine();

            QPointF pos;
            switch (coordType)
            {
                case DegMinSec:
                {
                    pos = lambert::GeoToDegDecimal(file_line, ';', ' ');
                    break;
                }
                case DegMin:
                {
                    break;
                }
                case Deg:
                {
                    pos = lambert::GeoToDegDecimal(file_line, ';');
                    break;
                }
            }

            QPointF scrpos;
            lambert::GeoToScreen(scrpos, pos);
            m_points << (scrpos);
        }
        file.close();

        this->setPolygon(m_points);

        return true;
    }
    else
    {
        return false;
    }
}
