#include "coordinateconverter.h"

#include <QStringList>


float lambert::GeoToDegDecimal(QString deg, QString min, QString sec)
{
    float d, m;

    m = min.toFloat() + sec.toFloat() / 60;

    return d = deg.toFloat() + m / 60;
}

float lambert::GeoToDegDecimal(QString deg, QString min)
{
    float d;

    return d = deg.toFloat() + min.toFloat() / 60;
}

void lambert::GeoToScreen(float &lat, float &lon, float geoLat, float geoLon)
{
    qreal f, l;     //CoordY/X in radians

    f = qDegreesToRadians(geoLat);
    l = qDegreesToRadians(geoLon);


    qreal nh = qLn( qCos(B_LAT1) / qCos(B_LAT2) );
    qreal nl = qLn( qTan(M_PI_4+B_LAT2/2) / qTan(M_PI_4+B_LAT1/2) );

    qreal n = nh / nl;

    qreal F = (qCos(B_LAT1)*qPow((qTan(M_PI_4+B_LAT1/2)), n)) / n;

    qreal r0 = F * qPow((qCos(M_PI_4+Z_LAT/2)/qSin(M_PI_4+Z_LAT/2)), n);
    qreal r = F * qPow((qCos(M_PI_4+f/2)/qSin(M_PI_4+f/2)), n);

    lon = r*qSin(n*(l-Z_LON));
    lat = r0 - r*qCos(n*(l-Z_LON));
    lat *= -1;
}

QPointF lambert::GeoToDegDecimal(QString coordinate, const char dividerLatLon, const char dividerDMS)
{
    QStringList posLotLan = coordinate.split(dividerLatLon);
    QString Lat = posLotLan.at(0);//shirota(y)
    QString Lon = posLotLan.at(1);//dolgota(x)

    //Longitude
    QStringList LonSplit = Lon.split(dividerDMS);

    float lonD = LonSplit.at(0).toFloat(), lonM = LonSplit.at(1).toFloat(), lonS = LonSplit.at(2).toFloat();
    lonM += lonS / 60;
    lonD += lonM / 60;

    //Latitude
    QStringList LatSplit = Lat.split(dividerDMS);
    float latD = LatSplit.at(0).toFloat(), latM = LatSplit.at(1).toFloat(), latS = LatSplit.at(2).toFloat();
    latM += latS / 60;
    latD += latM / 60;

    return QPointF(lonD, latD);
}

void lambert::GeoToScreen(QPointF &scr, const QPointF geo)
{
    qreal f, l;     //CoordY/X in radians

    f = qDegreesToRadians(geo.y());
    l = qDegreesToRadians(geo.x());


    qreal nh = qLn( qCos(B_LAT1) / qCos(B_LAT2) );
    qreal nl = qLn( qTan(M_PI_4+B_LAT2/2) / qTan(M_PI_4+B_LAT1/2) );

    qreal n = nh / nl;

    qreal F = (qCos(B_LAT1)*qPow((qTan(M_PI_4+B_LAT1/2)), n)) / n;

    qreal r0 = F * qPow((qCos(M_PI_4+Z_LAT/2)/qSin(M_PI_4+Z_LAT/2)), n);
    qreal r = F * qPow((qCos(M_PI_4+f/2)/qSin(M_PI_4+f/2)), n);

    scr.setX(r*qSin(n*(l-Z_LON)));
    scr.setY((-1)*(r0 - r*qCos(n*(l-Z_LON))));

}

QPointF lambert::GeoToDegDecimal(QString coordinate, const char dividerLatLon)
{
    QStringList posLotLan = coordinate.split(dividerLatLon);
    QString Lat = posLotLan.at(0);//shirota(y)
    QString Lon = posLotLan.at(1);//dolgota(x)

    //Longitude
    float lonD = Lon.toFloat();

    //Latitude
    float latD = Lat.toFloat();

    return QPointF(lonD, latD);
}
