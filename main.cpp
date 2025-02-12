#include "maze.h"
#include <iostream>

using namespace std;

int main() {
    int width = 21, height = 11;

    Maze maze(width, height);
    maze.generateMaze();

    cout << "Generated Maze:\n";
    maze.displayMaze();

    cout << "\nSolving Maze...\n";
    maze.markSolution();

    cout << "\nSolved Maze:\n";
    maze.displayMaze();

    return 0;
}
