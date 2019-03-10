#include "radarwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RadarWindow w;
    w.showMaximized();

    return a.exec();
}
