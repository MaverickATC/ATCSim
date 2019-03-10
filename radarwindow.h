#ifndef RADARWINDOW_H
#define RADARWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

#include "radarview.h"
#include "radarscene.h"
#include "sector.h"
#include "border.h"
#include "point.h"
#include "pointlist.h"
#include "target.h"

namespace Ui {
class RadarWindow;
}

class RadarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RadarWindow(QWidget *parent = nullptr);
    ~RadarWindow();

private slots:
    void toolbarVis();
    void scaleChange(int value);
    void centerSelect();
    void sectorFill(int val);

private:
    void setMenus();
    void setPoints(QString filename);

    void mousePressEvent(QMouseEvent *event);

    Ui::RadarWindow *ui;

    RadarView *m_radarView;
    RadarScene *m_radarScene;

    Border *m_borderUA;
    Sector *m_tma;
    PointList m_points;
    Target *m_target;

    bool m_toolbarVis;
    bool m_centerSelect;

    const int SCALE_FACTOR = 100;
};

#endif // RADARWINDOW_H
