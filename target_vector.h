#ifndef TARGET_VECTOR_H
#define TARGET_VECTOR_H

#include <QGraphicsLineItem>



class Target_Vector :public QGraphicsLineItem
{
public:
    Target_Vector(QGraphicsItem *parent = nullptr);

    void SetStart(QPointF pos);
    void SetLength(float len);    //in nm per sec
    void SetTrack(float trck);  //in degrees
    void SetTime(int min);  //in minutes

private:
    void createLine();

    QPointF m_start;
    QPen *m_pen;
    float m_track;
    float m_length;
    int m_time;

    QVector<QGraphicsEllipseItem *> m_min_points;


};

#endif // TARGET_VECTOR_H
