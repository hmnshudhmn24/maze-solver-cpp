#include "maze.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Maze::Maze(int w, int h) : width(w), height(h) {
    grid.resize(height, vector<char>(width, '#'));
}

void Maze::generateMaze() {
    srand(time(0));
    for (int i = 1; i < height - 1; i += 2) {
        for (int j = 1; j < width - 1; j += 2) {
            grid[i][j] = ' ';
            int direction = rand() % 4;
            int dx = 0, dy = 0;

            switch (direction) {
                case 0: dy = -1; break;
                case 1: dy = 1; break;
                case 2: dx = -1; break;
                case 3: dx = 1; break;
            }

            int newX = j + dx, newY = i + dy;
            if (newX > 0 && newX < width - 1 && newY > 0 && newY < height - 1) {
                grid[newY][newX] = ' ';
            }
        }
    }
    grid[1][0] = 'S'; // Start
    grid[height - 2][width - 1] = 'E'; // End
}

void Maze::displayMaze() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

bool Maze::solveMaze(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height || grid[y][x] == '#' || grid[y][x] == '+') {
        return false;
    }
    if (grid[y][x] == 'E') {
        return true;
    }

    grid[y][x] = '+';

    if (solveMaze(x + 1, y) || solveMaze(x, y + 1) || solveMaze(x - 1, y) || solveMaze(x, y - 1)) {
        return true;
    }

    grid[y][x] = ' ';
    return false;
}

void Maze::markSolution() {
    solveMaze(1, 0);
}
