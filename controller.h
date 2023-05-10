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
    bool isTouchingMaze();
//    std::vector<QLineF> generateDrawMaterial(const QSize sizeOfWindow);
    Labyrinth maze;
};

#endif // CONTROLLER_H
