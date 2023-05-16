#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QString>
#include <random>
#include "time.h"

class Maze
{
public:

    Maze(size_t size = 0, const QString name = "");

//    void printMaze();
    const std::vector<std::vector<std::pair<bool, bool>>>& getWalls();
    void generateMaze(const size_t size);
    void generateFromFile(const std::string& s);

private:
    // within the generateMaze function
    void emptyWorkingLine();
    void assignUniqueSets();
    void addVWalls(const size_t row);
    void mergeSets(const size_t i, const size_t set);
    void addHWalls(const size_t row);
    bool isUnique(const size_t set);
    void checkedHorizontalWalls(const size_t row);
    void prepNewLine(const size_t row);
    void addEndLine();


    QString name_ = "";
    size_t size_;
    size_t counter_ = 1;
    std::vector<size_t> working_line_;
    std::vector<std::vector<std::pair<bool, bool>>> vert_hor_walls_;
};



#endif // MAZE_H
