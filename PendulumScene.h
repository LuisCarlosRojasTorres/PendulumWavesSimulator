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

    const double PI = 3.141592;
    const double g = 9.8182;

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

    double altura = 600;

    double L1 = 520;
    double L2 = 480;
    double L3 = 440;
    double L4 = 400;
    double L5 = 360;
    double L6 = 320;
    double L7 = 280;
    double L8 = 240;
    double L9 = 200;
    double L10 = 160;
    double L11 = 120;
    double L12 = 80;

    double w1 = 2*PI/(60.0/15);
    double w2 = 2*PI/(60.0/16);
    double w3 = 2*PI/(60.0/17);

    double w4 = 2*PI/(60.0/18);
    double w5 = 2*PI/(60.0/19);
    double w6 = 2*PI/(60.0/20);

    double w7 = 2*PI/(60.0/21);
    double w8 = 2*PI/(60.0/22);
    double w9 = 2*PI/(60.0/23);

    double w10 = 2*PI/(60.0/24);
    double w11 = 2*PI/(60.0/25);
    double w12 = 2*PI/(60.0/26);

    //variables

    std::vector<double> vectorOfLengths;
    std::vector<double> vectorOfOmegas;
    std::vector<double> vectorOfThetas;

    double initialTetha = 20*PI/180;
    double t = 0; //timeInMiliseconds
    double maxNumOfCyclesPerMinute = 31;
    double initialLength = 80;
    double radius = 15;

    std::vector<std::shared_ptr<PendulumGraphicsItem>> vectorOfPendulums;

};

#endif // PENDULUMSCENE_H
