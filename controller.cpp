#include "controller.h"

std::vector<QLineF> Controller::generateField()
{
    std::vector<QLineF> result;
    result.push_back(QLineF({0, 0}, { numOfPath_*coef_ , 0}));
    for (size_t i = 1; i < numOfPath_ + 1; ++i) {
        result.push_back(QLineF({0, (i-1)*coef_}, {0, i*coef_}));
        for (size_t j = 1; j < numOfPath_ + 1; ++j) {
            if(maze_.getWalls()[i-1][j-1].first) {
                result.push_back(QLine({j*coef_, (i-1)*coef_}, {j*coef_, i*coef_}));
            }
        }
        for (size_t j = 1; j < numOfPath_+1; ++j) {
            if(maze_.getWalls()[i-1][j-1].second) {
                result.push_back(QLine({(j -1)*coef_, i*coef_}, { j*coef_, i*coef_}));
            }
        }
    }
    return result;
}
