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

std::vector<QLineF> Controller::generatePath()
{
    std::vector<QLineF> result;
    if (path_.size() > 1) {
        QLineF line;
        for (auto i = 0; i < path_.size() - 1; ++i) {
            QPointF begin(path_[i].first * coef_ + coef_*0.5, path_[i].second * coef_ + coef_*0.5),
                    end(path_[i + 1].first * coef_ + coef_*0.5, path_[i + 1].second * coef_ + coef_*0.5);
            line = QLineF(begin, end);
            result.push_back(line);
        }
    }
    return result;
}

void Controller::addPathPoint(int direction)
//direction: 1-w, 2-a, 3-s, 4-d
{
    if (direction == 3) {
        if (!maze_.getWalls()[currPathPoint_.first][currPathPoint_.second].second){
            path_.push_back({currPathPoint_.first + 1, currPathPoint_.second});
        }
    }
    currPathPoint_ = path_[path_.size() - 1];
    currPathPoint = QPointF(currPathPoint_.first * coef_ + 0.5 * coef_,
                            currPathPoint_.second * coef_ + 0.5 * coef_);
}

