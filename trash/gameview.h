#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include "gamescene.h"
#include "model.h"

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView(QWidget *parent = nullptr);
    ~GameView();
protected:
    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
private:
    GameScene *gameScene_;
    int mode_ = 0;
};
#endif // GAMEVIEW_H

