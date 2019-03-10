#include "border.h"
#include "coordinateconverter.h"
#include <QFile>

Border::Border(QString filename, MapObject::coordType coordType, RadarScene *scene, QObject *parent):
        MapObject (scene, parent)
{
    readFile(filename, coordType);

    this->setPen(*m_pen);
    this->setBrush(*m_lineBrush);

    m_scene->addItem(this);

}

void Border::Scale(qreal factor)
{
    this->setScale(factor);
}

bool Border::readFile(QString filename, MapObject::coordType coordType)
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
