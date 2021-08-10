#include "PendulumGraphicsItem.h"
#include <QPainter>

PendulumGraphicsItem::PendulumGraphicsItem( QGraphicsItem *parent)
    :
      QGraphicsItem(parent)
{

}

PendulumGraphicsItem::PendulumGraphicsItem(QPointF centerOfBall, double radius, QGraphicsItem *parent)
    :
      centerOfBall(centerOfBall),
      radius(radius),
      colorOfBall(ColorOfBall::Yellow),
      QGraphicsItem(parent)
{
    this->setSize();
}

PendulumGraphicsItem::PendulumGraphicsItem(QPointF centerOfBall, double radius,
                                           ColorOfBall colorOfBall, QGraphicsItem *parent)
    :
      centerOfBall(centerOfBall),
      radius(radius),
      colorOfBall(colorOfBall),
      QGraphicsItem(parent)
{
    this->setSize();
}

void PendulumGraphicsItem::setCenterOfBall(QPointF centerOfBall)
{
    this->centerOfBall = centerOfBall;
}

void PendulumGraphicsItem::setRadius(double radius)
{
    this->radius = radius;
}

QPointF PendulumGraphicsItem::getCenterOfBall() const
{
    return this->centerOfBall;
}

double PendulumGraphicsItem::getRadius() const
{
    return this->radius;
}

QSizeF PendulumGraphicsItem::getSize() const
{
    return this->pendulumGraphicsItemSize;
}

void PendulumGraphicsItem::setSize()
{
    this->pendulumGraphicsItemSize = QSize(radius,radius);
}

QRectF PendulumGraphicsItem::boundingRect() const
{
    return QRectF(centerOfBall.x()-radius,centerOfBall.y()-radius,
                  centerOfBall.x()+radius,centerOfBall.y()+radius);
}

void PendulumGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void) option;
    (void) widget;

    switch (colorOfBall) {
    case ColorOfBall::Blue :
        painter->setBrush(Qt::yellow);
        break;
    case ColorOfBall::Green :
        painter->setBrush(Qt::green);
        break;
    case ColorOfBall::Red :
        painter->setBrush(Qt::red);
        break;
    case ColorOfBall::Yellow :
        painter->setBrush(Qt::yellow);
        break;
    }

    painter->setPen(Qt::black);
    painter->drawEllipse(centerOfBall,radius,radius);
}
