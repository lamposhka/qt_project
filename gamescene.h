#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "controller.h"
#include <QPen>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    Controller* controller;
    GameScene(QObject *parent = 0);
    void drawNewMaze(const size_t size, const size_t stretch, QPen pen);

protected:
    virtual void keyPressEvent(QKeyEvent * keyEvent);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);


private:
    QGraphicsPixmapItem * player;
    bool isStartSolving_ = false;
};

#endif // GAMESCENE_H
