#ifndef PENDULUMGRAPHICSITEM_H
#define PENDULUMGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPointF>
#include <QSizeF>

class PendulumGraphicsItem : public QGraphicsItem
{    
public:
    PendulumGraphicsItem( QGraphicsItem *parent = nullptr );
    PendulumGraphicsItem( QPointF centerOfBall, double radius, QGraphicsItem *parent = nullptr );

    void setCenterOfBall(QPointF centerOfBall);
    void setRadius(double radius);
    void setSize();

    QPointF getCenterOfBall() const;
    double getRadius() const;
    QSizeF getSize() const;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    double radius;
    QPointF centerOfBall;
    QSizeF pendulumGraphicsItemSize;
};

#endif // PENDULUMGRAPHICSITEM_H
