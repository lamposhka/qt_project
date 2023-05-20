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
        currPathPoint = QPointF(coef_ * 0.5, coef_ * 0.5);
    }
    std::vector<QLineF> generateField();
    std::vector<QLineF> generatePath();
    void addPathPoint(int direction);
    QPointF currPathPoint;
private:
    Maze maze_;
    size_t numOfPath_;
    size_t coef_;
    std::vector<std::pair<size_t, size_t>> path_;
    std::pair<size_t, size_t> currPathPoint_ = {0, 0};
};

#endif // CONTROLLER_H
