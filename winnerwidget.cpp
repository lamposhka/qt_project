#include "winnerwidget.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>


WinnerWidget::WinnerWidget(QWidget *parent)
    : QWidget{parent}
{
    auto* layout = new QVBoxLayout(this);
    auto *player = new QMediaPlayer(this);


    auto *playlist = new QMediaPlaylist(player);
    playlist->addMedia(QUrl("qrc:/animation/scary-creepy.mp4"));

    auto* videoWidget = new QVideoWidget(this);
    player->setVideoOutput(videoWidget);

    layout->addWidget(videoWidget);
    videoWidget->setMinimumSize(200,200);
    videoWidget->show();
    playlist->setCurrentIndex(1);
    player->play();

}
