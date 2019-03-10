#include "mapobject.h"
#include "radarscene.h"

MapObject::MapObject(QGraphicsScene *scene, QObject *parent) : QObject(parent)
{
    m_scene = scene;

    m_penColor = new QColor(Qt::black);
    m_brushColor = new QColor(125, 125, 125);
    m_lineBrush = new QBrush(*m_penColor);
    m_lineBrush->setStyle(Qt::NoBrush);
    m_sectorBrush = new QBrush(*m_brushColor);
    m_textBrush = new QBrush(QColor(Qt::white));
    m_pen = new QPen(*m_penColor);
    m_pen->setJoinStyle(Qt::MiterJoin);
    m_pen->setWidth(0);
}




