// Mohammad Zahid
// HW3 Recursion
#ifndef CREATURE_H
#define CREATURE_H
#pragma once
#include "maze.h"
#include <ostream>
using namespace std;
class Creature {
  public:
    friend ostream& operator<<(ostream& out, const Creature& creature);
  public:
    //constructor
    Creature(int row, int col);
    // solver method
    string solve(Maze& maze);
    //checks if we are at the exit
    bool atExit(const Maze& maze) const;
    // moving functions
    string goNorth(Maze& maze);
    string goSouth(Maze& maze);
    string goEast(Maze& maze);
    string goWest(Maze& maze);

  private:
    int row;
    int col;
    string Path;
};
#endif // CREATURE_H