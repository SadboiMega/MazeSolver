// Mohammad Zahid
// HW3 Recursion
#include <iostream>
#include "creature.h"
#include "maze.h"
void test() {
    Maze M("maze1.txt");
    cout << M << endl;
    Creature C(1, 6);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
void test1() {
    Maze M("maze2.txt");
    cout << M << endl;
    Creature C(1, 6);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}
// Main test functions
int main() {
    test();
    test1();
    cout << "Done!" << std::endl;
    return 0;
}