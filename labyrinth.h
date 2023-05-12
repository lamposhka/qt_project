#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <vector>
#include <random>
#include "time.h"

class Maze
{
public:
    Maze(size_t size = 5);

    void printMaze();
    const std::vector<std::vector<std::pair<bool, bool>>>& getWalls();

private:
    void emptyWorkingLine();
    void assignUniqueSets();
    void addVWalls(const size_t row);
    void mergeSets(const size_t i, const size_t set);

    void addHWalls(const size_t row);
//    bool ifOnlyWithoutBorder(size_t row, size_t set);

    bool isUnique(const size_t set);
    void checkedHorizontalWalls(const size_t row);

    void prepNewLine(const size_t row);
    void addEndLine();

    size_t counter_ = 1;
    size_t size_;
    std::vector<size_t> working_line_;
    std::vector<std::vector<std::pair<bool, bool>>> vert_hor_walls_;
};



#endif // LABYRINTH_H
