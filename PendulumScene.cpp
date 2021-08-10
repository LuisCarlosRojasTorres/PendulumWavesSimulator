#include "PendulumGraphicsItem.h"
#include "PendulumScene.h"
#include "ToQtCoordinates.h"

#include <iostream>
#include <QGraphicsSceneMouseEvent>

#define XPOS 0.0
#define YPOS 0.0
#define WIDTH 450
#define HEIGHT 650

PendulumScene::PendulumScene(QObject *parent)
    :
      QGraphicsScene(XPOS, YPOS, WIDTH, HEIGHT, parent)
{
    addRect(XPOS,YPOS,WIDTH,HEIGHT,QPen(Qt::black));
    toQtCoordinates = new ToQtCoordinates(
                ToQtCoordinates::Type::MidPoint,WIDTH,HEIGHT);

    int count =1;
    for(int i = 1; i <= 15; i++){
        vectorOfOmegas.push_back(2*PI/(60.0/(maxNumOfCyclesPerMinute-i)));
        vectorOfLengths.push_back(initialLength+2*radius*(i-1));

        vectorOfPendulums.push_back(
                    std::make_shared<PendulumGraphicsItem>(
                        toQtCoordinates->convertToQtCoordinates(
                            QPointF(
                                -vectorOfLengths.back()*sin(initialTetha),
                                altura - vectorOfLengths.back()*cos(initialTetha)
                                )
                            ),
                        radius
                        )
                    );

        addItem(vectorOfPendulums.back().get());

        count++;
    }


}

void PendulumScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    std::cout << "Scene position: " << mouseEvent->scenePos().x() << " , "  << mouseEvent->scenePos().y() << std::endl;
    std::cout << "Scene: " << this->width() << " , "  << this->height() << std::endl;


}

void PendulumScene::onUpdate()
{
    vectorOfThetas.clear();

    t +=0.05;

    for(int i = 0; i < vectorOfLengths.size(); i++){

        vectorOfThetas.push_back(initialTetha*cos(vectorOfOmegas.at(i)*t + PI));

        vectorOfPendulums.at(i)->setCenterOfBall(
                    toQtCoordinates->convertToQtCoordinates(
                        QPointF(
                            vectorOfLengths.at(i)*sin(vectorOfThetas.at(i)),
                            altura - vectorOfLengths.at(i)*cos(vectorOfThetas.at(i))
                            )
                        )
                    );
    }

    update();
}
