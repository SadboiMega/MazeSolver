// Mohammad Zahid
// HW3 Recursion
#ifndef MAZE_H
#define MAZE_H
#pragma once
#include <ostream>
using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
    friend ostream& operator<<(ostream& out, const Maze& maze);
  public:
    explicit Maze(const string& fileName);
    // check for wall
    bool IsWall(int row, int column) const;
    // check for path
    bool IsPath(int row, int column) const;
    bool IsVisited(int row, int column) const;
    void MarkAsVisited(int row, int column);
    // check if exit Row
    int getExitRow() const;
    // check if exit Column
    int getExitColumn() const;
    // check if clear
    bool IsClear(int row, int column) const;
    // marks as path
    void MarkAsPath(int row, int column);

  private:
    // max size of array
    static const int MAX_SIZE = 100;
    char field[MAX_SIZE][MAX_SIZE]; // rows , columns
    int width;
    int height;
    int exitRow;
    int exitColumn;
};
#endif // MAZE_H