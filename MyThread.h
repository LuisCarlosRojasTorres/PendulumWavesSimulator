#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT;

public:
    MyThread(QObject *parent = nullptr);
    ~MyThread();
    void start(int msec, Priority p);
    bool getIsRunning() const;
    int getMsec() const;

signals:
    void already();
protected:
    void run();
private:
    bool isRunning;
    int mMsec;
};

#endif // MYTHREAD_H
