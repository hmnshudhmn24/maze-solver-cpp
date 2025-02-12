#ifndef MAZE_H
#define MAZE_H

#include <vector>

class Maze {
private:
    int width, height;
    std::vector<std::vector<char>> grid;

public:
    Maze(int w, int h);
    void generateMaze();
    void displayMaze() const;
    bool solveMaze(int x, int y);
    void markSolution();
};

#endif // MAZE_H
