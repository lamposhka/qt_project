#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include "controller.h"
#include <QPen>

class GameField : public QWidget
{
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void setMazeParameters(const size_t size, const size_t stretch, QPen pen);
signals:

private:
    Controller* controller_;
    size_t numOfPath_;
    size_t stretch_;
    QPen pen_;
    bool is_start = false;
};

#endif // GAMEFIELD_H
