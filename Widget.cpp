#include "Widget.h"
#include "ui_Widget.h"

#include "PendulumScene.h"
#include "MyThread.h"

#include <iostream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mScene = new PendulumScene(this);
    ui->graphicsView->setScene(mScene);

    mThread = new MyThread(this);
    //layout()->setMargin(0);

    ui->cB_colors->addItem(QString("Mono-Yellow"));
    ui->cB_colors->addItem(QString("Bi"));
    ui->cB_colors->addItem(QString("Tri"));

    connect(ui->cB_colors, QOverload<int>::of(&QComboBox::currentIndexChanged),
            mScene, &PendulumScene::setPendulumColors);

    connect(ui->pB_start, &QPushButton::clicked,
            this, &Widget::start);

    connect(ui->pB_stop, &QPushButton::clicked,
            this, &Widget::stop);

    connect(ui->sB_initialAngle, QOverload<int>::of(&QSpinBox::valueChanged),
            mScene, &PendulumScene::setInitialTetha);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::start()
{
    if(!mThread->getIsRunning()){
        std::cout<<"Widget::start: " << std::endl;
        mThread->start(timeIncrementMillisecond,MyThread::HighPriority);
        connect(mThread, &MyThread::already, mScene, &PendulumScene::onUpdate );
    }else{
        mThread->setIsRunning(true);
        std::cout<<"Widget::start: Is already running!" << std::endl;
    }
}

void Widget::stop()
{
    std::cout<<"Widget::stop: " << std::endl;
    mScene->setPendulumSceneToTimeZero();
    mThread->setIsRunning(false);
    disconnect(mThread, &MyThread::already, mScene, &PendulumScene::onUpdate );
}
