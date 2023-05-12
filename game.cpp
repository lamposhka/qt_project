#include "game.h"

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    gameScene_ = new GameScene;

    size_t s = 40;
    size_t coef = 25;

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);

    gameScene_->drawNewMaze(s, coef, pen);

    setScene(gameScene_);
    gameScene_->setSceneRect(0, 0, s*coef, s*coef);

    fitInView(gameScene_->sceneRect(), Qt::KeepAspectRatioByExpanding);
//    setFixedSize(800, 800);
}

Game::~Game()
{
}

