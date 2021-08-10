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

    ToQtCoordinates *toQtCoordinates;

    double altura = 600;

    std::vector<double> vectorOfLengths;
    std::vector<double> vectorOfOmegas;
    std::vector<double> vectorOfThetas;

    double initialTetha = 20*PI/180;
    double t = 0; //timeInMiliseconds
    double maxNumOfCyclesPerMinute = 26;
    double initialLength = 80;
    double radius = 15;

    std::vector<std::shared_ptr<PendulumGraphicsItem>> vectorOfPendulums;

};

#endif // PENDULUMSCENE_H
