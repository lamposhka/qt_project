#include "gameview.h"

GameView::GameView(QWidget *parent)
    : QGraphicsView(parent)
{
    resize(800, 800);
    gameScene_ = new GameScene;

    size_t s = 40;
    size_t coef = 800/s;

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);

    gameScene_->drawNewMaze(s, coef, pen);

    setScene(gameScene_);
    gameScene_->setSceneRect(0, 0, 798, 798);
    setMouseTracking(true);

//    fitInView(gameScene_->sceneRect(), Qt::KeepAspectRatioByExpanding);
//    setFixedSize(800, 800);
}

GameView::~GameView()
{
}

void GameView::mouseMoveEvent(QMouseEvent *event)
{
    if (mode_ == 0) {
        gameScene_->mousePosUpdate(event);
    }
}

