#include "MyThread.h"

MyThread::MyThread(QObject *parent)
    :
      QThread(parent)
{
    isRunning = false;
    mMsec = 0;
}

MyThread::~MyThread()
{
   QThread::quit();
   QThread::wait();
}

void MyThread::start(int msec, Priority p)
{
    mMsec = msec;
    isRunning = true;
    QThread::start(p);
}

bool MyThread::getIsRunning() const
{
    return isRunning;
}

int MyThread::getMsec() const
{
    return mMsec;
}

void MyThread::run(){
    while(isRunning){
        emit already();
        msleep(mMsec);
    }
}
