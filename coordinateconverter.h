#ifndef COORDINATECONVERTER_H
#define COORDINATECONVERTER_H

#include <QString>
#include <QPointF>
#include <QtMath>

namespace lambert {

    float GeoToDegDecimal(QString deg, QString min, QString sec);
    float GeoToDegDecimal(QString deg, QString min);
    QPointF GeoToDegDecimal(QString coordinate, const char dividerLatLon, const char dividerDMS);
    QPointF GeoToDegDecimal(QString coordinate, const char dividerLatLon);

    void GeoToScreen(float &lat, float &lon, const float geoLat, const float geoLon);
    void GeoToScreen(QPointF &scr, const QPointF geo);

    const float Z_LAT = qDegreesToRadians(52.0f);   //0,0 point latitude
    const float Z_LON = qDegreesToRadians(23.0f);   //0.0 point longitude
    const float B_LAT1 = qDegreesToRadians(46.0f);  //basic latitude1
    const float B_LAT2 = qDegreesToRadians(52.0f);  //basic latitude2
}


#endif // COORDINATECONVERTER_H
