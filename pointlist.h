#ifndef POINTLIST_H
#define POINTLIST_H

#include "point.h"

#include <QMap>



class PointList : public QMap<QString, Point*>
{
public:
    PointList();
};

#endif // POINTLIST_H
