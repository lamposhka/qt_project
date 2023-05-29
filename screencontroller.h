#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H
#include "screen_stack/screenstack.h"
#include "game.h"
#include "mainmenu.h"
#include "winnerwidget.h"
#include <QMediaPlayer>


class ScreenController : public ScreenStack
{
    Q_OBJECT
public:
    explicit ScreenController(QWidget *parent = nullptr);
public slots:
    void onLevelSelected();
    void onFinished();
    void onBackSelected();

    void onStartSelected();
    void onExitSelected();
protected:

private:
    Game* game_;
    MainMenu* mainMenu_;
    WinnerWidget* winnerWidget_;
    bool music_ = true;
    QMediaPlayer* player_;
    QMediaPlaylist *playlist_;
};

#endif // SCREENCONTROLLER_H
