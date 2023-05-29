#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model/maze.h"
#include <QPointF>
#include <QLineF>
#include <QSize>

class Controller
{
public:
    Controller(const size_t numOfPath, const size_t coef) :
        maze_(numOfPath), numOfPath_(numOfPath), coef_(coef) {
    }
    std::vector<QLineF> generateField();
    std::pair<int, int> particularShift = {0, 0};

private:
    Maze maze_;
    size_t numOfPath_;
    size_t coef_;
};

#endif // CONTROLLER_H
