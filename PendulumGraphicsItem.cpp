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

    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::black);
    painter->drawEllipse(centerOfBall,radius,radius);
}
