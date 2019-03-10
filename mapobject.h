#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QObject>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QGraphicsScene>

class MapObject : public QObject
{
    Q_OBJECT
public:
    enum coordType{
        DegMinSec,
        DegMin,
        Deg
    };


    explicit MapObject(QGraphicsScene *scene, QObject *parent = nullptr);

    virtual void Scale(qreal factor) = 0;

protected:
    QGraphicsScene *m_scene;
    QPen *m_pen;
    QBrush *m_lineBrush;
    QBrush *m_textBrush;
    QBrush *m_sectorBrush;
    QColor *m_brushColor;
    QColor *m_penColor;


signals:

public slots:
};

#endif // MAPOBJECT_H
