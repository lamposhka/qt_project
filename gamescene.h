#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QObject *parent = 0);
protected:
    virtual void keyPressEvent(QKeyEvent * keyEvent);

private:
    QGraphicsPixmapItem * player;
};

#endif // GAMESCENE_H
