#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include "controller.h"
#include <QPen>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class GameField : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameField(const size_t numOfPath, const size_t stretch, QPen pen, QWidget *parent = nullptr);
    void drawMaze();
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void setMazeParameters(const size_t size, const size_t stretch, QPen pen);
private slots:
    void onTimer();
signals:
    void startTimer();
    void endGame(int time);
private:
    QGraphicsEllipseItem* cursor_;
    QGraphicsRectItem* finish_;
    QGraphicsScene* scene_;
    Controller* controller_;
    size_t numOfPath_;
    int stretch_;
    QPen pen_;
    bool is_start = false;
    QTimer* timer_;

};

#endif // GAMEFIELD_H
