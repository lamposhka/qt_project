#ifndef MAINMENU_H
#define MAINMENU_H
#include <QWidget>
#include "levelwidget.h"
#include "mode.h"

class MainMenu: public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget* parent = nullptr);
    Mode mode = RANDOM;
public slots:
    void changeMode();
signals:
    void settingsSelected();
    void helpSelected();
    void startSelected();
    void exitSelected();
protected:
    LevelWidget* levelWidget_;
};

#endif // MAINMENU_H
