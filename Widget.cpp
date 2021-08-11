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
    mThread = new MyThread(this);

    ui->graphicsView->setScene(mScene);

    //layout()->setMargin(0);

    ui->cB_colors->addItem(QString("Mono-Yellow"));
    ui->cB_colors->addItem(QString("Bi"));
    ui->cB_colors->addItem(QString("Tri"));
    ui->cB_colors->addItem(QString("Rainbow"));

    connect(ui->cB_colors, QOverload<int>::of(&QComboBox::currentIndexChanged),
            mScene, &PendulumScene::setPendulumColors);

    connect(ui->pB_start, &QPushButton::clicked,
            this, &Widget::start);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::start()
{
    if(!mThread->getIsRunning()){
        mThread->start(10,MyThread::HighPriority);
        connect(mThread, &MyThread::already, mScene, &PendulumScene::onUpdate );
    }else{
        std::cout<<"Is already running!" << std::endl;
    }
}
