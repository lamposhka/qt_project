#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "controller.h"
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = 0);
    void drawNewMaze(const size_t size, const size_t stretch, QPen pen);
public slots:
    void keyPressEvent(QKeyEvent *event);
signals:
    void start();
    void finished();
private:
    Controller* controller;
};

#endif // GAMESCENE_H
