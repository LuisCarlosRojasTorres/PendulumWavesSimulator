#include "ToQtCoordinates.h"

ToQtCoordinates::ToQtCoordinates(int width, int height)
    :
      typeOfTransformation(Type::Basic),
      width(width),
      height(height),
      initialP(QPointF()),
      endP(QPointF())
{
}

ToQtCoordinates::ToQtCoordinates( Type typeOfTransformation, int width, int height)
    :
      typeOfTransformation(typeOfTransformation),
      width(width),
      height(height),
      initialP(QPointF()),
      endP(QPointF())
{    
}

ToQtCoordinates::ToQtCoordinates(Type typeOfTransformation, int width, int height, QPointF initialP, QPointF endP)
    :
      typeOfTransformation(typeOfTransformation),
      width(width),
      height(height),
      initialP(initialP),
      endP(endP)
{
}

QPointF ToQtCoordinates::convertToQtCoordinates(QPointF realCoordinates)
{
    switch(typeOfTransformation){
    case Type::Basic :
        return QPointF(realCoordinates.x(), this->height - realCoordinates.y());
    break;
    case Type::MidPoint :
        return QPointF(realCoordinates.x() + this->width/2, this->height - realCoordinates.y());
    break;
    case Type::Scaled :
        double deltaPx = endP.x() - initialP.x();
        double deltaPy = endP.y() - initialP.y();

        return QPointF((realCoordinates.x()-initialP.x())*this->width/deltaPx,
                       (realCoordinates.y()-initialP.y())*this->height/deltaPy);
    break;
    }
    return QPointF();
}


