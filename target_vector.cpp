#include "target_vector.h"

#include <QPen>

Target_Vector::Target_Vector(QGraphicsItem *parent):
    QGraphicsLineItem(parent),
    m_pen(new QPen(Qt::blue)),
    m_track(270.0),
    m_length(10.0),
    m_time(1)
{
    this->setPen(*m_pen);
    createLine();
    for(int i = 1; i < 6; i++)
    {
        m_min_points.push_back(new QGraphicsEllipseItem(m_start.x()-1, m_start.y()-1, 2.0f, 2.0f, this));
    }

}

void Target_Vector::SetStart(QPointF pos)
{
    m_start = pos;
    createLine();
}

void Target_Vector::SetLength(float len)
{
    m_length = len;
    createLine();
}

void Target_Vector::SetTrack(float trck)
{
    m_track = trck;
    createLine();
}

void Target_Vector::SetTime(int min)
{
    m_time = min;
    createLine();
}

void Target_Vector::createLine()
{
    QLineF l;
    l.setP1(m_start);
    l.setAngle(m_track);
    if(m_time != 0)
    {
        l.setLength(m_length * m_time);
    }
    else
    {
        l.setLength(0);
    }

    this->setLine(l);
    //l.setLength(ias * 60 / 10);
}
