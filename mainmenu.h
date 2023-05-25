#ifndef MAINMENU_H
#define MAINMENU_H
#include <QWidget>
#include "levelwidget.h"


class MainMenu: public QWidget
{
    Q_OBJECT
public:
    MainMenu(QWidget* parent = nullptr);
signals:
    void settingsSelected();
    void helpSelected();
    void startSelected();
protected:
    LevelWidget* levelWidget_;
};

#endif // MAINMENU_H
