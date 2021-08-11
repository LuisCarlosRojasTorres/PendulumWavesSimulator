#ifndef PENDULUMGRAPHICSITEM_H
#define PENDULUMGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPointF>
#include <QSizeF>

enum ColorOfBall{
    Yellow,
    Blue,
    Red,
    Green
};

class PendulumGraphicsItem : public QGraphicsItem
{
public:    

    PendulumGraphicsItem( QGraphicsItem *parent = nullptr );
    PendulumGraphicsItem( QPointF centerOfBall, double radius,
                          QGraphicsItem *parent = nullptr );
    PendulumGraphicsItem( QPointF centerOfBall, double radius,
                          ColorOfBall colorOfBall,
                          QGraphicsItem *parent = nullptr );

    void setCenterOfBall(QPointF centerOfBall);
    void setRadius(double radius);
    void setSize();
    void setIndex(int index);

    QPointF getCenterOfBall() const;
    double getRadius() const;
    QSizeF getSize() const;
    int getIndex() const;

    void setColor(ColorOfBall colorBall);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0);

private:
    int index = 0;
    double radius;
    QPointF centerOfBall;
    QSizeF pendulumGraphicsItemSize;

    ColorOfBall colorOfBall = ColorOfBall::Yellow;
};

#endif // PENDULUMGRAPHICSITEM_H
