#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H
#include "screen_stack/screenstack.h"
#include "game.h"
#include "mainmenu.h"


class ScreenController : public ScreenStack
{
    Q_OBJECT
public:
    explicit ScreenController(QWidget *parent = nullptr);
public slots:
    void onLevelSelected();
    void onFinished(bool win);
    void onHelpSelected();
    void onBackSelected();
    void onSettingsSelected();

    void onStartSelected();
protected:

private:
    Game* game_;
    MainMenu* mainMenu_;
};

#endif // SCREENCONTROLLER_H
