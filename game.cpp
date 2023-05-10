#include "game.h"

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    gameScene_ = new GameScene;

    size_t s = 10;
    controller_ = new Controller(s);

    size_t coef = 25;
    QLineF line({0, 0}, { s*coef , 0});
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    gameScene_->addLine(line, pen);


    for (size_t i = 1; i < s + 1; ++i) {
        line = QLineF({0, (i-1)*coef}, {0, i*coef});
        gameScene_->addLine(line, pen);
        for (size_t j = 1; j < s + 1; ++j) {
            if(controller_->maze.getWalls()[i-1][j-1].first) {
                line = QLine({j*coef, (i-1)*coef}, {j*coef, i*coef});
                gameScene_->addLine(line, pen);
            }
        }
        for (size_t j = 1; j < s+1; ++j) {
            if(controller_->maze.getWalls()[i-1][j-1].second) {
                line = QLine({(j -1)*coef, i*coef}, { j*coef, i*coef});
                gameScene_->addLine(line, pen);
            }
        }
    }
    setScene(gameScene_);
    gameScene_->setSceneRect(0, 0, s*coef, s*coef);
    fitInView(gameScene_->sceneRect(), Qt::KeepAspectRatio);
//    setFixedSize(800, 800);
}

Game::~Game()
{
}

