#include "gamescene.h"
#include <QDebug>


GameScene::GameScene(QObject *parent) : QGraphicsScene(parent)
{
    controller = new Controller(0);
    cursor_ = new QGraphicsEllipseItem(0, 0, 3, 3);
    addItem(cursor_);
}

void GameScene::drawNewMaze(const size_t size, const size_t stretch, QPen pen)
{
    controller = new Controller(size);
    setSceneRect(0, 0, size*stretch, size*stretch);

    for (size_t i = 0; i < controller->generateField(size, stretch).size(); ++i) {
        addLine(controller->generateField(size, stretch)[i], pen);
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return) {
        qDebug() << "start";
    } else if (event->key() == Qt::Key_A) {

    }
    QGraphicsScene::keyPressEvent(event);
}
