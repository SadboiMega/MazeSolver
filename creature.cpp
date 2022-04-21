// Mohammad Zahid
// HW3 Recursion
#include <iostream>
#include "creature.h"

ostream &operator<<(ostream &Out, const Creature &Creature) {
  Out << "C(" << Creature.row << Creature.col << ")" << endl;
  return Out;
}
//constructor
Creature::Creature(int row, int col) : row(row), col(col) {
    string Path;
}
//returns if we are at the exit or not
bool Creature::atExit(const Maze &Maze) const {
  return (row == Maze.getExitRow() && col == Maze.getExitColumn());
}
//solves maze
string Creature::solve(Maze &Maze) {
  string Path;
  if (atExit(Maze))
    return "";
  Path = goEast(Maze);
  if (Path.empty()) {
    Path = goSouth(Maze);
    if (Path.empty()) {
      Path = goWest(Maze);
      if (Path.empty())
        Path = goNorth(Maze);
    }
  }
  if (Path.empty()) {
      Path = "No exit"; 
  }
  return Path;
}
// returns directions
string Creature::goEast(Maze &Maze) {
  string way("E");

  if (Maze.IsClear(row, col + 1)) {
    Maze.MarkAsPath(row, ++col);
    // cout << row << ", " << col << endl << Maze;
    if (atExit(Maze))
      return "E";
    string E, S, N;
    if ((E = goEast(Maze)).empty()) {
      if ((S = goSouth(Maze)).empty()) {
        if ((N = goNorth(Maze)).empty()) {
          way.pop_back();
          Maze.MarkAsVisited(row, col--);
          // cout << row << ", " << col<< endl << Maze;
        } else
          way.append(N);
      } else
        way.append(S);
    } else
      way.append(E);
  } else
    way.pop_back();
  return way;
}
// returns directions
string Creature::goSouth(Maze &Maze) {
  string way("S");

  if (Maze.IsClear(row + 1, col)) {
    Maze.MarkAsPath(++row, col);
    if (atExit(Maze))
      return "S";
    string S, W, E;
    if ((S = goSouth(Maze)).empty()) {
      if ((W = goWest(Maze)).empty()) {
        if ((E = goEast(Maze)).empty()) {
          way.pop_back();
          Maze.MarkAsVisited(row--, col);
        } else
          way.append(E);
      } else
        way.append(W);
    } else
      way.append(S);
  } else
    way.pop_back();
  return way;
}
// returns directions
string Creature::goWest(Maze &Maze) {
  string way("W");

  if (Maze.IsClear(row, col - 1)) {
    Maze.MarkAsPath(row, --col);
    if (atExit(Maze))
      return "W";
    string W, N, S;
    if ((W = goWest(Maze)).empty()) {
      if ((N = goNorth(Maze)).empty()) {
        if ((S = goSouth(Maze)).empty()) {
          way.pop_back();
          Maze.MarkAsVisited(row, col++);
        } else
          way.append(S);
      } else
        way.append(N);
    } else
      way.append(W);
  } else
    way.pop_back();
  return way;
}
// returns directions
string Creature::goNorth(Maze &Maze) {
  string way("N");

  if (Maze.IsClear(row - 1, col)) {
    Maze.MarkAsPath(--row, col);
    if (atExit(Maze))
      return "N";
    string N, E, W;
    if ((N = goNorth(Maze)).empty()) {
      if ((E = goEast(Maze)).empty()) {
        if ((W = goWest(Maze)).empty()) {
          way.pop_back();
          Maze.MarkAsVisited(row++, col);
        } else
          way.append(W);
      } else
        way.append(E);
    } else
      way.append(N);
  } else
    way.pop_back();
  return way;
}