#include "screencontroller.h"

ScreenController::ScreenController(QWidget *parent) : ScreenStack(parent)
{
    mainMenu_ = new MainMenu(this);
    connect(mainMenu_, SIGNAL(settingsSelected()), this, SLOT(onSettingsSelected()));
    connect(mainMenu_, SIGNAL(helpSelected()), this, SLOT(onHelpSelected()));
    connect(mainMenu_, SIGNAL(startSelected()), this, SLOT(onStartSelected()));
    push(mainMenu_);

    game_ = new Game(this);
    connect(game_, SIGNAL(back()),  this, SLOT(onBackSelected()));
    connect(game_, SIGNAL(finished(int)), this, SLOT(onFinished()));
    connect(game_, SIGNAL(help()), this, SLOT(onHelpSelected()));
    game_->hide();

}

void ScreenController::onLevelSelected()
{
    push(game_);
    this->adjustSize();
}

void ScreenController::onFinished()
{
    mainMenu_->show();
    push(mainMenu_);
    this->adjustSize();
}

void ScreenController::onHelpSelected()
{
    this->adjustSize();
}

void ScreenController::onBackSelected()
{
    mainMenu_->show();
    push(mainMenu_);
    this->adjustSize();
}

void ScreenController::onSettingsSelected()
{

}

void ScreenController::onStartSelected()
{
    game_ = new Game(this);
    connect(game_, SIGNAL(back()),  this, SLOT(onBackSelected()));
    connect(game_, SIGNAL(finished(int)), this, SLOT(onFinished()));
    connect(game_, SIGNAL(help()), this, SLOT(onHelpSelected()));
    push(game_);
    this->adjustSize();
}
