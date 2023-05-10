#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include "gamescene.h"
#include "controller.h"

class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
private:
    GameScene *gameScene_;
    Controller *controller_;
};
#endif // GAME_H
