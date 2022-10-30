#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <vector>

using namespace std;

class EightPuzzle {
    private:
        int cost = 1;
        const int PUZZLE_SIZE = 9;
        vector<int> currentState = vector<int>(PUZZLE_SIZE);
    public:
    /* Constructors */

    /* Default constructor initializes to goal state */
        EightPuzzle();
    /* Constructor takes in a specified state */
        EightPuzzle(vector<int> inputState);

    /* Operators: */
        void move_left();
        void move_right();
        void move_up();
        void move_down();

    /* Output current state */
        void outputCurrentState();
    /* Output whether current state is goal state */
        void outputCurrentStateStatus();
    /* Public helper function that will check whether current state is goal state */
        bool isGoalState();
    private:
    /* Private helper function that returns the location of 0 */
        int getZeroPosition();
    
};

#endif