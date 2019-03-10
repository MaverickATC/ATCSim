#ifndef TARGET_HISTORY_H
#define TARGET_HISTORY_H

#include <QGraphicsPixmapItem>
#include <QVector>



class Target_History : public QVector<QGraphicsPixmapItem*>
{
public:
    Target_History();
};

#endif // TARGET_HISTORY_H
