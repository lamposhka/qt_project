#include "game.h"
#include "buttons/basicbutton.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPen>
#include <QLabel>

Game::Game(QWidget *parent)
    : QWidget{parent}
{

    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(p);

    QPen pen(Qt::SolidLine);
    pen.setColor(Qt::white);
    pen.setWidth(3);
    gameField_ = new GameField(numOfPath_, 780/numOfPath_, pen);
    gameField_->setFixedSize(781, 781);
    gameField_->setSceneRect(0, 0, gameField_->contentsRect().width(), gameField_->contentsRect().height());
//    gameField_.setMazeParameters(numOfPath_, 780/numOfPath_, pen);



    BasicStyledButton* back = new BasicStyledButton("back", this);
    back->setFixedSize(50, 30);
    BasicStyledButton* help = new BasicStyledButton("help", this);
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
    layout->addWidget(gameField_);
    layout->setMargin(0);


    setFixedSize(layout->sizeHint().width(), layout->sizeHint().height());

    gameField_->setFocus();

    updateTimer_ = new QTimer();
    updateTimer_->setInterval(10);



    connect(back, SIGNAL(clicked()), this, SIGNAL(back()));
    connect(help, SIGNAL(clicked()), this, SIGNAL(help()));

    connect(gameField_, SIGNAL(endGame(int)), this, SIGNAL(finished(int)));
    connect(gameField_, SIGNAL(startTimer()), this, SLOT(onStart()));
    connect(updateTimer_, SIGNAL(timeout()), this, SLOT(onTimer()));
}

void Game::setup(size_t numOfPaths = 0)
{

}

void Game::onStart()
{
    updateTimer_->start();
    elapsedTimer_.start();
}

void Game::onTimer()
{
    int secs = elapsedTimer_.elapsed()/ 1000;
    QString time = QVariant(secs).toString() + " sec";
    timerLable_->setText(time);
}
