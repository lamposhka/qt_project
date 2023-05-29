#include "game.h"
#include "buttons/basicbutton.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPen>
#include <QLabel>
#include <QFontDatabase>

Game::Game(Mode mode, QWidget *parent)
    : QWidget{parent}
{
    switch (mode) {
    case RANDOM:
        numOfPath_ = rand()%28 + 3;
        break;
    case HARD:
        numOfPath_ = 30;
        break;
    case NORMAL:
        numOfPath_ = 15;
        break;
    case EASY:
        numOfPath_ = 7;
        break;
    default:
        break;
    }
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(p);

    QPen pen(Qt::SolidLine);
    pen.setColor(Qt::white);
    pen.setWidth(3);
    gameField_ = new GameField(numOfPath_, 780/numOfPath_, pen);
    gameField_->setFixedSize(numOfPath_ * (780/numOfPath_) + 3, numOfPath_ * (780/numOfPath_) + 3);
    gameField_->setSceneRect(0, 0, gameField_->contentsRect().width(), gameField_->contentsRect().height());
//    gameField_.setMazeParameters(numOfPath_, 780/numOfPath_, pen);



    BasicStyledButton* back = new BasicStyledButton("back", this);
//    back->setFixedSize(50, 30);
//    BasicStyledButton* help = new BasicStyledButton("help", this);
//    help->setFixedSize(50, 30);


    QFontDatabase::addApplicationFont(":/fonts/ARCADECLASSIC.TTF");
    QFont font = QFont("ArcadeClassic", 15, 1);

    timerLable_ = new QLabel("Press any key to begin.");
    QPalette p1 = timerLable_->palette();
    p1.setColor(QPalette::WindowText, Qt::white);
    timerLable_->setFont(font);
    timerLable_->setPalette(p1);
    timerLable_->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignHCenter);

    QHBoxLayout *upperWidgets = new QHBoxLayout(this);
    upperWidgets->addWidget(back);
    upperWidgets->addWidget(timerLable_);
//    upperWidgets->addWidget(help);
//    upperWidgets->setContentsMargins(5, 5, 5, 1);


    layout->addLayout(upperWidgets);
    layout->addWidget(gameField_);
    layout->setMargin(30);

    BasicStyledButton* exit = new BasicStyledButton("exit", this);


//    setFixedSize(layout->sizeHint().width(), layout->sizeHint().height());


    gameField_->setFocus();

    updateTimer_ = new QTimer();
    updateTimer_->setInterval(10);



    connect(back, SIGNAL(clicked()), this, SIGNAL(back()));

    connect(gameField_, SIGNAL(endGame(int)), this, SLOT(onFinished()));
    connect(gameField_, SIGNAL(endGame(int)), this, SIGNAL(finished()));
    connect(gameField_, SIGNAL(startTimer()), this, SLOT(onStart()));
    connect(updateTimer_, SIGNAL(timeout()), this, SLOT(onTimer()));
    connect(exit, SIGNAL(clicked(bool)), this, SIGNAL(exit()));
}

QString Game::Time()
{
    return timerLable_->text();
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

void Game::onFinished()
{
    updateTimer_->stop();
}
