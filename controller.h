#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "labyrinth.h"
#include <QPointF>
#include <QLineF>
#include <QSize>

class Controller
{
public:
    Controller(const size_t size) : maze(size) {}
    bool isTouchingMaze(const QPointF point);
    std::vector<QLineF> generateDrawMaterial( const size_t numOfPath, const size_t coef);
    Maze maze;
};

#endif // CONTROLLER_H
