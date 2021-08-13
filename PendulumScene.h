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

    void setPendulumSceneToTimeZero();

public slots:
    void onUpdate();
    void setPendulumColors(int index);
    void setInitialTetha(double initialTetha);

    void setPendulumnPositionsAtTimet(double currentTime);
    void setTimeIncrement(double timeIncrement);

private:

    const double altura = 600;
    const double PI = 3.141592;
    const double g = 9.8182;

    ToQtCoordinates *toQtCoordinates;

    std::vector<double> vectorOfLengths;
    std::vector<double> vectorOfOmegas;
    std::vector<double> vectorOfThetas;
    std::vector<std::shared_ptr<PendulumGraphicsItem>> vectorOfPendulums;

    double currentTime = 0; //timeInMiliseconds
    double initialLength = 80;
    double initialTetha = 20*PI/180;
    double maxNumOfCyclesPerMinute = 65;
    double radius = 15;
    double timeIncrement = 0.01;

    int numOfPendulums = 15;



};

#endif // PENDULUMSCENE_H
