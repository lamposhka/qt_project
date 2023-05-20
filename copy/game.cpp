#include "game.h"
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPen>
#include <QLabel>

Game::Game(QWidget *parent)
    : QWidget{parent}
{
    gameField_.setFixedSize(781, 781);
    QPen pen(Qt::SolidLine);
    pen.setWidth(3);
//    scene_.drawNewMaze(numOfPath_, 780/numOfPath_, pen);
    gameField_.setMazeParameters(numOfPath_, 780/numOfPath_, pen);



    QPushButton* back = new QPushButton("back", this);
    back->setFixedSize(50, 30);
    QPushButton* help = new QPushButton("help", this);
    help->setFixedSize(50, 30);
    timerLable_ = new QLabel("Press enter to begin.");
    timerLable_->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter);

    QHBoxLayout *upperWidgets = new QHBoxLayout(this);
    upperWidgets->addWidget(back);
    upperWidgets->addWidget(timerLable_);
    upperWidgets->addWidget(help);
    upperWidgets->setContentsMargins(5, 5, 5, 1);

    layout->addLayout(upperWidgets);
    layout->addWidget(&gameField_);
    layout->setMargin(0);


    setFixedSize(layout->sizeHint().width(), layout->sizeHint().height());

    gameField_.setFocus();



    connect(back, SIGNAL(clicked()), this, SIGNAL(back()));
    connect(help, SIGNAL(clicked()), this, SIGNAL(help()));

}

void Game::setup(size_t numOfPaths = 0)
{

}

void Game::onStart()
{

}

void Game::onFinished()
{

}

void Game::onTimer()
{
    timerLable_->setText("hello");
}