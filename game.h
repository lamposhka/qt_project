#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QElapsedTimer>
#include "gamescene.h"
#include <QLabel>

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void setup(size_t numOfPaths);
protected slots:
    void onStart();
    void onFinished();
    void onTimer();
signals:
    void finished(bool win);
    void back();
    void exit();
    void help();
protected:
    size_t numOfPath_ = 20;
    GameScene scene_;
    QGraphicsView view_;
    QTimer timer_;
    QLabel* timerLable_;
};

#endif // GAME_H
