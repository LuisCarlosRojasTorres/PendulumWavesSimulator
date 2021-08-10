#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class PendulumScene;
class MyThread;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void setPendulumColors(int index);

private:
    Ui::Widget *ui;

    PendulumScene *mScene;
        MyThread *mThread;

signals:
        void update();
};
#endif // WIDGET_H
