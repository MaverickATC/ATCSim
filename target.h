#ifndef TARGET_H
#define TARGET_H

#include "mapobject.h"
#include "target_history.h"
#include "target_pic.h"
#include "target_vector.h"



class Target : public MapObject
{
public:
    const float _NM = 0.000289308f;

    struct TargetData
    {
        //  c/s, sq, afl, cfl, tfl, hdg, track, gs, ias, tas, mach, v/spd, pos, geoPos
    };
    Target(QGraphicsScene *scene, QObject *parent = nullptr);

    void Scale(qreal factor);

private:
    Target_Pic *m_pic;
    //Target_History m_history;
    Target_Vector *m_vector;
    QPointF m_pos;
};

#endif // TARGET_H
