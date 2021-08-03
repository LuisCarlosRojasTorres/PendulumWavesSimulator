#ifndef PENDULUMSCENE_H
#define PENDULUMSCENE_H

#include <memory>
#include <QGraphicsScene>

class PendulumGraphicsItem;
class ToQtCoordinates;

class PendulumScene : public QGraphicsScene
{
    Q_OBJECT
public:
    PendulumScene(QObject *parent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
public slots:
    void onUpdate();
private:
    PendulumGraphicsItem *pendulum1;
    PendulumGraphicsItem *pendulum2;
    PendulumGraphicsItem *pendulum3;

    PendulumGraphicsItem *pendulum4;
    PendulumGraphicsItem *pendulum5;
    PendulumGraphicsItem *pendulum6;

    PendulumGraphicsItem *pendulum7;
    PendulumGraphicsItem *pendulum8;
    PendulumGraphicsItem *pendulum9;

    PendulumGraphicsItem *pendulum10;
    PendulumGraphicsItem *pendulum11;
    PendulumGraphicsItem *pendulum12;
    ToQtCoordinates *toQtCoordinates;

    const double PI = 3.141592;

    double altura = 600;
    double g = 9.8182;

    double L1 = 300;
    double L2 = 280;
    double L3 = 260;
    double L4 = 240;
    double L5 = 220;
    double L6 = 200;
    double L7 = 180;
    double L8 = 160;
    double L9 = 140;
    double L10 = 120;
    double L11 = 100;
    double L12 = 80;

    double w1 = 2*PI/3;
    double w2 = 2*PI/2.95;
    double w3 = 2*PI/2.9;

    double w4 = 2*PI/2.85;
    double w5 = 2*PI/2.8;
    double w6 = 2*PI/2.75;

    double w7 = 2*PI/2.7;
    double w8 = 2*PI/2.65;
    double w9 = 2*PI/2.6;

    double w10 = 2*PI/2.55;
    double w11 = 2*PI/2.5;
    double w12 = 2*PI/2.45;

    //variables

    std::vector<double> vectorOfLengths;
    std::vector<double> vectorOfOmegas;

    double initialTetha = 30*PI/180;
    double t = 0; //timeInMiliseconds

    std::shared_ptr<PendulumGraphicsItem> vectorOfPendulums;

};

#endif // PENDULUMSCENE_H
