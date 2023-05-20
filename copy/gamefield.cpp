#include "gamefield.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::paintEvent(QPaintEvent *event)
{
    QPainter painter = QPainter(this);
    controller_ = new Controller(numOfPath_, stretch_);

    painter.setPen(pen_);
    for (size_t i = 0; i < controller_->generateField().size(); ++i) {
        painter.drawLine(controller_->generateField()[i]);
    }

//    painter.setPen(Qt::red);
//    for (size_t i = 0; i < controller_->generatePath().size(); ++i) {
//        painter.drawLine(controller_->generatePath()[i]);
//    }

//    painter.drawEllipse(controller_->currPathPoint, 6, 6);
}

void GameField::keyPressEvent(QKeyEvent *event)
{
    if (!is_start) {
        is_start = true;
    }
    if (event->key() == Qt::Key_W){
        qDebug() << "w";
        controller_->addPathPoint(1);
    } else if (event->key() == Qt::Key_A){
        qDebug() << "a";
        controller_->addPathPoint(2);
    } else if (event->key() == Qt::Key_S){
        qDebug() << "s";
        controller_->addPathPoint(3);
    } else if (event->key() == Qt::Key_D){
        qDebug() << "d";
        controller_->addPathPoint(4);
    }
}

void GameField::setMazeParameters(const size_t size, const size_t stretch, QPen pen)
{
    numOfPath_ = size;
    stretch_= stretch;
    pen_ = pen;
}
