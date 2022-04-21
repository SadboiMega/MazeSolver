// Mohammad Zahid
// HW3 Recursion
#include "maze.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

ostream& operator<<(ostream& out, const Maze& maze) {
    for (int row = 0; row < maze.height; row++) {
        for (int col = 0; col < maze.width; col++) {
            out << maze.field[row][col];
        }
        out << endl;
        }

        out << endl;

    return out;
}

Maze::Maze(const string& fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    inFile >> width >> height;
    inFile >> exitRow >> exitColumn;

    string str;
    getline(inFile, str);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            inFile.get(field[row][col]);
        }

        getline(inFile, str);
    }
}
 //returns the where the exit row is
int Maze::getExitRow() const { 
    return exitRow; 
}
//returns the where the exit column is
int Maze::getExitColumn() const { 
    return exitColumn; 
}
//returns true or false if the space is clear or not
bool Maze::IsClear (int row, int column) const { 
    if (field[row][column] == ' ') {
        return true;
    }

    return false;
}
//sets our path to * to show our current path
void Maze::MarkAsPath(int row, int column) { 
    field[row][column] = '*'; 
}
// sets path as visited so we dont loop
void Maze::MarkAsVisited(int row, int column) { 
    field[row][column] = '+'; 
}
// returns true if the space is a wall or not
bool Maze::IsWall(int row, int column) const {
    return field[row][column] == 'x';
}
// returns true or false depending on if the space is within the maze
bool Maze::IsPath(int row, int column) const {
   return (row <= width && column <= height);
}
// returns true or false if visited
bool Maze::IsVisited(int row, int column) const {
    return field[row][column] == '*';
}