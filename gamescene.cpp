#include "gamescene.h"


GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{
    controller = new Controller(0);
//    player = addPixmap(QPixmap(":/images/texture.gif"));
    //    setBackgroundBrush(QBrush(QColor(255,255,255), QPixmap(":/images/texture.gif")));
}

void GameScene::drawNewMaze(const size_t size, const size_t stretch, QPen pen)
{
    controller = new Controller(size);
    for (size_t i = 0; i < controller->generateDrawMaterial(size, stretch).size(); ++i) {
        addLine(controller->generateDrawMaterial(size, stretch)[i], pen);
    }
}

void GameScene::keyPressEvent(QKeyEvent *keyEvent)
{

}

void GameScene::mousePressEvent(QMouseEvent *event)
{

}

void GameScene::mouseMoveEvent(QMouseEvent *event)
{

}
