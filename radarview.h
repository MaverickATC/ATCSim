#ifndef RADARVIEW_H
#define RADARVIEW_H

#include <QGraphicsView>

class RadarView : public QGraphicsView
{
public:
    RadarView(int w, int h, QWidget *parent = nullptr);
};

#endif // RADARVIEW_H
