#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model/maze.h"
#include <QPointF>
#include <QLineF>
#include <QSize>

class Controller
{
public:
    Controller(const size_t size) : maze(size) {}
    std::vector<QLineF> generateField( const size_t numOfPath, const size_t coef);
    Maze maze;
};

#endif // CONTROLLER_H
