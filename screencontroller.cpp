#include "screencontroller.h"
#include <QMediaPlaylist>
#include <QAudioOutput>

ScreenController::ScreenController(QWidget *parent) : ScreenStack(parent)
{
    playlist_ = new QMediaPlaylist(this);
    playlist_->addMedia(QUrl("qrc:/music/playlist/Plantasia.mp3"));
    playlist_->setPlaybackMode(QMediaPlaylist::Loop);

    player_ = new QMediaPlayer(this);
    player_->setPlaylist(playlist_);
    player_->play();

    mainMenu_ = new MainMenu(this);
    connect(mainMenu_, SIGNAL(startSelected()), this, SLOT(onStartSelected()));
    connect(mainMenu_, SIGNAL(exitSelected()), this, SLOT(onExitSelected()));
    push(mainMenu_);
    showFullScreen();

}

void ScreenController::onLevelSelected()
{
    push(game_);
}

void ScreenController::onFinished()
{
    winnerWidget_ = new WinnerWidget(game_->Time(), this);
    connect(winnerWidget_, SIGNAL(exit()), this , SLOT(onExitSelected()));
    connect(winnerWidget_, SIGNAL(back()), this , SLOT(onBackSelected()));
    playlist_->addMedia(QUrl("qrc:/music/playlist/Music_to_Soothe_the_Savage_Snake_Plant.mp3"));
    playlist_->next();

    winnerWidget_->show();
    push(winnerWidget_);
}


void ScreenController::onBackSelected()
{
    push(mainMenu_);
    playlist_->addMedia(QUrl("qrc:/music/playlist/Plantasia.mp3"));
    playlist_->next();
}

void ScreenController::onStartSelected()
{
    playlist_->addMedia(QUrl("qrc:/music/playlist/sellamusicnet_Mort_Garson_-_Rhapsody_in_Green_65350151.mp3"));
    playlist_->next();

    game_ = new Game(mainMenu_->mode, this);
    connect(game_, SIGNAL(back()),  this, SLOT(onBackSelected()));
    connect(game_, SIGNAL(finished()), this, SLOT(onFinished()));
    connect(game_, SIGNAL(exit()), this, SLOT(onExitSelected()));
    push(game_);
}

void ScreenController::onExitSelected()
{
    close();
}
