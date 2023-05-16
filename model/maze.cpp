#include "maze.h"

Maze::Maze(const size_t size, const QString name)
{
    name_ = name;
    generateMaze(size);
}

void generateFromFile(const std::string& s) {
    std::ifstream fin(s);
    if (!fin) {
        throw std::invalid_argument("Wrong filename!\n");
    }
    // TO_DO
}
