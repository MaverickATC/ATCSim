#include "target.h"

Target::Target(QGraphicsScene *scene, QObject *parent):
    MapObject (scene, parent)

{
    m_pos.setX(0.034);
    m_pos.setY(0.036);
    m_pic = new Target_Pic();
    m_vector = new Target_Vector();
    m_pic->SetPos(m_pos);
    m_vector->SetStart(m_pos);
    float ias = (600.0f / 60.0f) * _NM;    //nm per min
    m_vector->SetLength(ias/10.0);

    m_scene->addItem(m_pic);
    m_scene->addItem(m_vector);
}

void Target::Scale(qreal factor)
{
    QPointF p = m_pos*factor;
    m_pic->SetPos(p);
    m_vector->SetStart(p);
    m_vector->SetLength((600.0f / 60.0f) * _NM *factor);
}
