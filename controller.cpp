#include "controller.h"

std::vector<QLineF> Controller::generateField( const size_t numOfPath, const size_t coef)
{
    std::vector<QLineF> result;
    result.push_back(QLineF({0, 0}, { numOfPath*coef , 0}));
    for (size_t i = 1; i < numOfPath + 1; ++i) {
        result.push_back(QLineF({0, (i-1)*coef}, {0, i*coef}));
        for (size_t j = 1; j < numOfPath + 1; ++j) {
            if(maze.getWalls()[i-1][j-1].first) {
                result.push_back(QLine({j*coef, (i-1)*coef}, {j*coef, i*coef}));
            }
        }
        for (size_t j = 1; j < numOfPath+1; ++j) {
            if(maze.getWalls()[i-1][j-1].second) {
                result.push_back(QLine({(j -1)*coef, i*coef}, { j*coef, i*coef}));
            }
        }
    }
    return result;
}

