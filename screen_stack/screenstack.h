#ifndef SCREENSTACK_H
#define SCREENSTACK_H
#include <QStack>
#include <QGridLayout>
#include <QWidget>

class ScreenStack : public QWidget
{
    Q_OBJECT
public:
    ScreenStack(QWidget *parent = 0);
public slots:
    void push(QWidget* widget);
    void pop();
    int lenghth();
    QWidget& front();
private:
    QStack<QWidget*> widgets_;
    QGridLayout layout_;
};

#endif // SCREENSTACK_H
