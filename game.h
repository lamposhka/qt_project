#ifndef GAME_H
#define GAME_H

#include <QMainWindow>

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();
};
#endif // GAME_H
