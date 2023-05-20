#include "screencontroller.h"

ScreenController::ScreenController(QWidget *parent) : ScreenStack(parent)
{
    mainMenu_ = new MainMenu(this);
    connect(mainMenu_, SIGNAL(settingsSelected()), this, SLOT(onSettingsSelected()));
    connect(mainMenu_, SIGNAL(helpSelected()), this, SLOT(onHelpSelected()));
    connect(mainMenu_, SIGNAL(startSelected()), this, SLOT(onStartSelected()));
    push(mainMenu_);

    game_ = new Game(this);
    connect(game_, SIGNAL(back()),  this, SLOT(pop()));
    connect(game_, SIGNAL(finished(bool)), this, SLOT(on_finished(bool)));
    connect(game_, SIGNAL(help()), this, SLOT(on_help_selected()));
    game_->hide();

}

void ScreenController::onLevelSelected()
{
    push(game_);
}

void ScreenController::onFinished(bool win)
{
}

void ScreenController::onHelpSelected()
{
    push(game_);
}

void ScreenController::onBackSelected()
{
//    mainMenu_->show();
//    push(mainMenu_);
    pop();
    this->front().show();
}

void ScreenController::onSettingsSelected()
{

}

void ScreenController::onStartSelected()
{
    game_ = new Game(this);
    connect(game_, SIGNAL(back()),  this, SLOT(pop()));
    connect(game_, SIGNAL(finished(bool)), this, SLOT(on_finished(bool)));
    connect(game_, SIGNAL(help()), this, SLOT(on_help_selected()));
    push(game_);
}
