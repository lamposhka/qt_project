#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QElapsedTimer>
#include "gamefield.h"
#include <QLabel>

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    void setup(size_t numOfPaths);
protected slots:
    void onStart();
    void onTimer();
signals:
    void finished(int time);
    void back();
    void exit();
    void help();
protected:
    size_t numOfPath_ = 15;
    GameField* gameField_;
    QTimer* updateTimer_;
    QElapsedTimer elapsedTimer_;
    QLabel* timerLable_;
};

#endif // GAME_H
