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

        std::cout << " - i : " << count << " periodo: " << vectorOfOmegas.back() << "  length: " << vectorOfLengths.back() <<std::endl;
        count++;
    }

    std::cout << " - vectorOfOmegas size: " << vectorOfOmegas.size() << std::endl;



//    //1
//    pendulum1 = new PendulumGraphicsItem();
//    pendulum1->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L1*sin(initialTetha),altura - L1*cos(initialTetha))));
//    pendulum1->setRadius(20);
//    pendulum1->setSize();

//    addItem(pendulum1);
//    //2
//    pendulum2 = new PendulumGraphicsItem();
//    pendulum2->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L2*sin(initialTetha),altura - L2*cos(initialTetha))));
//    pendulum2->setRadius(20);
//    pendulum2->setSize();

//    addItem(pendulum2);
//    //3
//    pendulum3 = new PendulumGraphicsItem();
//    pendulum3->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L3*sin(initialTetha),altura - L3*cos(initialTetha))));
//    pendulum3->setRadius(20);
//    pendulum3->setSize();

//    addItem(pendulum3);
//    //4
//    pendulum4 = new PendulumGraphicsItem();
//    pendulum4->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L4*sin(initialTetha),altura - L4*cos(initialTetha))));
//    pendulum4->setRadius(20);
//    pendulum4->setSize();

//    addItem(pendulum4);
//    //5
//    pendulum5 = new PendulumGraphicsItem();
//    pendulum5->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L5*sin(initialTetha),altura - L5*cos(initialTetha))));
//    pendulum5->setRadius(20);
//    pendulum5->setSize();

//    addItem(pendulum5);
//    //6
//    pendulum6 = new PendulumGraphicsItem();
//    pendulum6->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L6*sin(initialTetha),altura - L6*cos(initialTetha))));
//    pendulum6->setRadius(20);
//    pendulum6->setSize();

//    addItem(pendulum6);
//    //7
//    pendulum7 = new PendulumGraphicsItem();
//    pendulum7->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L7*sin(initialTetha),altura - L7*cos(initialTetha))));
//    pendulum7->setRadius(20);
//    pendulum7->setSize();

//    addItem(pendulum7);
//    //8
//    pendulum8 = new PendulumGraphicsItem();
//    pendulum8->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L8*sin(initialTetha),altura - L8*cos(initialTetha))));
//    pendulum8->setRadius(20);
//    pendulum8->setSize();

//    addItem(pendulum8);
//    //9
//    pendulum9 = new PendulumGraphicsItem();
//    pendulum9->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L9*sin(initialTetha),altura - L9*cos(initialTetha))));
//    pendulum9->setRadius(20);
//    pendulum9->setSize();

//    addItem(pendulum9);
//    //10
//    pendulum10 = new PendulumGraphicsItem();
//    pendulum10->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L10*sin(initialTetha),altura - L10*cos(initialTetha))));
//    pendulum10->setRadius(20);
//    pendulum10->setSize();

//    addItem(pendulum10);
//    //11
//    pendulum11 = new PendulumGraphicsItem();
//    pendulum11->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L11*sin(initialTetha),altura - L11*cos(initialTetha))));
//    pendulum11->setRadius(20);
//    pendulum11->setSize();

//    addItem(pendulum11);
//    //12
//    pendulum12 = new PendulumGraphicsItem();
//    pendulum12->setCenterOfBall(
//                toQtCoordinates->convertToQtCoordinates(
//                    QPointF(-L12*sin(initialTetha),altura - L12*cos(initialTetha))));
//    pendulum12->setRadius(20);
//    pendulum12->setSize();

//    addItem(pendulum12);
}

void PendulumScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    std::cout << "Scene position: " << mouseEvent->scenePos().x() << " , "  << mouseEvent->scenePos().y() << std::endl;
    std::cout << "Scene: " << this->width() << " , "  << this->height() << std::endl;


}

void PendulumScene::onUpdate()
{
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
    std::cout << "t: " << t << std::endl;

//    double tetha1 = initialTetha*cos(w1*t+PI);
//    double tetha2 = initialTetha*cos(w2*t+PI);
//    double tetha3 = initialTetha*cos(w3*t+PI);

//    double tetha4 = initialTetha*cos(w4*t+PI);
//    double tetha5 = initialTetha*cos(w5*t+PI);
//    double tetha6 = initialTetha*cos(w6*t+PI);

//    double tetha7 = initialTetha*cos(w7*t+PI);
//    double tetha8 = initialTetha*cos(w8*t+PI);
//    double tetha9 = initialTetha*cos(w9*t+PI);

//    double tetha10 = initialTetha*cos(w10*t+PI);
//    double tetha11 = initialTetha*cos(w11*t+PI);
//    double tetha12 = initialTetha*cos(w12*t+PI);

//    pendulum1->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L1*sin(tetha1),altura - L1*cos(tetha1))));
//    pendulum2->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L2*sin(tetha2),altura - L2*cos(tetha2))));
//    pendulum3->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L3*sin(tetha3),altura - L3*cos(tetha3))));

//    pendulum4->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L4*sin(tetha4),altura - L4*cos(tetha4))));
//    pendulum5->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L5*sin(tetha5),altura - L5*cos(tetha5))));
//    pendulum6->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L6*sin(tetha6),altura - L6*cos(tetha6))));

//    pendulum7->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L7*sin(tetha7),altura - L7*cos(tetha7))));
//    pendulum8->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L8*sin(tetha8),altura - L8*cos(tetha8))));
//    pendulum9->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L9*sin(tetha9),altura - L9*cos(tetha9))));

//    pendulum10->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L10*sin(tetha10),altura - L10*cos(tetha10))));
//    pendulum11->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L11*sin(tetha11),altura - L11*cos(tetha11))));
//    pendulum12->setCenterOfBall(toQtCoordinates->convertToQtCoordinates(QPointF(L12*sin(tetha12),altura - L12*cos(tetha12))));
    update();
}
