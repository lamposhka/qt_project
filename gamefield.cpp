#include "gamefield.h"
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

GameField::GameField(const size_t numOfPath, const size_t stretch, QPen pen, QWidget *parent) : QGraphicsView(parent)
{
    setBackgroundBrush(Qt::black);
    pen_ = pen;
    stretch_ = stretch;
    numOfPath_ = numOfPath;
    controller_ = new Controller(numOfPath_, stretch_);

//    setFrameRect(QFrame::NoFrame);


    scene_ = new QGraphicsScene(this);
    setScene(scene_);

    cursor_ = new QGraphicsEllipseItem(-3, -3, 6, 6);
    cursor_->setPen(pen_);
    cursor_->setPos(stretch_*0.5, stretch*0.5);


    finish_ = new QGraphicsRectItem(0, 0, stretch, stretch);
    finish_->setPen(QPen(Qt::NoPen));
    finish_->setBrush(Qt::red);
    scene_->addItem(finish_);
    finish_->setPos(stretch_*(numOfPath - 1), stretch*(numOfPath - 1));

    scene_->addItem(cursor_);

    drawMaze();

    timer_ = new QTimer(this);
    timer_->setInterval(3*numOfPath_);
    timer_->start();
    connect(timer_, SIGNAL(timeout()), this, SLOT(onTimer()));
}

void GameField::drawMaze()
{
    for (size_t i = 0; i < controller_->generateField().size(); ++i) {
        scene_->addLine(controller_->generateField()[i])->setPen(pen_);
    }
}

void GameField::keyPressEvent(QKeyEvent *event)
{
    if (!is_start) {
        is_start = true;
        emit startTimer();
    }
    if (event->key() == Qt::Key_W){
        controller_->particularShift.second -= 1;
    } else if (event->key() == Qt::Key_A){
        controller_->particularShift.first -= 1;
    } else if (event->key() == Qt::Key_S){
        controller_->particularShift.second += 1;
    } else if (event->key() == Qt::Key_D){
        controller_->particularShift.first += 1;
    }
}

void GameField::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_W){
        controller_->particularShift.second += 1;
    } else if (event->key() == Qt::Key_A){
        controller_->particularShift.first += 1;
    } else if (event->key() == Qt::Key_S){
        controller_->particularShift.second -= 1;
    } else if (event->key() == Qt::Key_D){
        controller_->particularShift.first -= 1;
    }
}

void GameField::setMazeParameters(const size_t size, const size_t stretch, QPen pen)
{
    numOfPath_ = size;
    stretch_= stretch;
    pen_ = pen;
}

void GameField::onTimer()
{
    cursor_->moveBy(6*controller_->particularShift.first, 0);
    if(cursor_->collidesWithItem(finish_)) {
        emit endGame(true);
        timer_->stop();
    } else if(cursor_->collidingItems().size()) {
        cursor_->moveBy(-6*controller_->particularShift.first, 0);
    }


    cursor_->moveBy(0, 6*controller_->particularShift.second);
    if(cursor_->collidesWithItem(finish_)) {
        emit endGame(true);
    } else if(cursor_->collidingItems().size()) {
        cursor_->moveBy(0, -6*controller_->particularShift.second);
    }
}
