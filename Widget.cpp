#include "Widget.h"
#include "ui_Widget.h"

#include "PendulumScene.h"
#include "MyThread.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    mScene = new PendulumScene(this);
    mThread = new MyThread(this);

    ui->graphicsView->setScene(mScene);

    //layout()->setMargin(0);

    connect(mThread, &MyThread::already, mScene, &PendulumScene::onUpdate );
    mThread->start(10,MyThread::HighPriority);

    ui->cB_colors->addItem(QString("Mono"));
    ui->cB_colors->addItem(QString("Bi"));
    ui->cB_colors->addItem(QString("Tri"));
    ui->cB_colors->addItem(QString("Rainbow"));
}

Widget::~Widget()
{
    delete ui;
}

