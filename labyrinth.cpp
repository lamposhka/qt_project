#include "labyrinth.h"

Labyrinth::Labyrinth(const size_t size)
{
    srand(time(nullptr));
    size_ = size;
    working_line_ = std::vector<size_t>(size, 0);
    vert_hor_walls_ =
        std::vector<std::vector<std::pair<bool, bool>>>(size, std::vector<std::pair<bool, bool>>(size, {false, false}));

    emptyWorkingLine();
    for (size_t i = 0; i < size - 1; ++i) {
        assignUniqueSets();
        addVWalls(i);
        addHWalls(i);
        checkedHorizontalWalls(i);
        prepNewLine(i);
    }
    addEndLine();

}

void Labyrinth::emptyWorkingLine()
{
    for (auto &i: working_line_) {
        i = 0;
    }
}

void Labyrinth::assignUniqueSets()
{
    for (auto &i: working_line_) {
        if (i == 0) {
            i = counter_;
            ++counter_;
        }
    }
}

void Labyrinth::addVWalls(const size_t row)
{
    for (int col = 0; col < size_ - 1; ++col) {
        bool is_chosen = rand() % 2;

        if (working_line_[col] == working_line_[col + 1] || is_chosen) {
            vert_hor_walls_[row][col].first = true;
        }
        else {
            mergeSets(col, working_line_[col]);
        }
    }
    vert_hor_walls_[row][size_ - 1].first = true;
}

void Labyrinth::mergeSets(const size_t i, const size_t set)
{
    size_t temp = working_line_[i + 1];
    for (size_t col = 0; col < size_; ++col) {
        if (working_line_[col] == temp) {
            working_line_[col] = set;
        }
    }
}

void Labyrinth::addHWalls(const size_t row)
{
    for (int col = 0; col < size_; ++col) {
        bool is_chosen = rand() % 2;

//        if (is_chosen && !ifOnlyWithoutBorder(row, working_line_[col])) {
//            horizontal_walls_[row][col] = true;
//        }
        if (is_chosen && !isUnique(working_line_[col])) {
            vert_hor_walls_[row][col].second = true;
        }
    }
}

bool Labyrinth::isUnique(const size_t set)
{
    int counter = 0;
    for (size_t i = 0; i < size_; ++i) {
        if (working_line_[i] == set) {
            ++counter;
        }
    }
    return counter == 1;
}

void Labyrinth::checkedHorizontalWalls(const size_t row)
{
    for (size_t i = 0; i < size_; ++i) {
        int countHWalls = 0;
        for (int j = 0; j < size_; j++) {
            if (working_line_[j] == working_line_[i] && !vert_hor_walls_[row][j].second) {
                countHWalls++;
            }
        }
        if (countHWalls == 0) {
            vert_hor_walls_[row][i].second = false;
        }
    }
}

void Labyrinth::prepNewLine(const size_t row)
{
    for (size_t i = 0; i < size_; ++i) {
        if (vert_hor_walls_[row][i].second) {
            working_line_[i] = 0;
        }
    }
}

void Labyrinth::addEndLine()
{
    assignUniqueSets();
    addVWalls(size_ - 1);
    for (size_t i = 0; i < size_ - 1; ++i) {
        vert_hor_walls_[size_ - 1][i].second = true;
        if (working_line_[i] != working_line_[i + 1]) {
            vert_hor_walls_[size_ - 1][i].first = false;
            mergeSets(i, working_line_[i]);
        }
    }
    vert_hor_walls_[size_ - 1][size_ - 1].second = true;

}

void Labyrinth::printLabyrinth()
{
    // upper border
    for (size_t i = 0; i < size_; ++i) {
        std::cout << " -";
    }
    std::cout << " " << std::endl;
    // the actual maze
    for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
            if (j == 0) {
                std::cout << "|";
            }
            if (vert_hor_walls_[i][j].first) {
                std::cout << " |";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
        for (size_t j = 0; j < size_; ++j) {
            if (vert_hor_walls_[i][j].second) {
                std::cout << " -";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

}

const std::vector<std::vector<std::pair<bool, bool> > >& Labyrinth::getWalls()
{
    return vert_hor_walls_;
}
