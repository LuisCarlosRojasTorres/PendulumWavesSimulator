#ifndef TOQTCOORDINATES_H
#define TOQTCOORDINATES_H

#include <QPointF>

class ToQtCoordinates
{
public:
    enum Type{
        Basic,
        MidPoint,
        Scaled
    };

    ToQtCoordinates( int width, int height );
    ToQtCoordinates( Type typeOfTransformation, int width, int height );
    ToQtCoordinates( Type typeOfTransformation, int width, int height, QPointF initialP, QPointF endP );
    QPointF convertToQtCoordinates( QPointF realCoordinates );

private:
    Type typeOfTransformation;

    int width;
    int height;
    QPointF initialP, endP;

};

#endif // TOQTCOORDINATES_H
