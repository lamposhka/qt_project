#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QElapsedTimer>
#include "gamefield.h"
#include <QLabel>
#include "mode.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(Mode mode, QWidget *parent = nullptr);
    QString Time();
protected slots:
    void onStart();
    void onTimer();
    void onFinished();
signals:
    void finished();
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
