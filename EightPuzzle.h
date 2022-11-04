#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <vector>

using namespace std;

class EightPuzzle {
    public:
        vector<int> currentState = vector<int>();
        int heuristic = 0;  // How far the current state is from the goal state
    private:
        
        const int PUZZLE_SIZE = 9;
        bool invalidMove = false;
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
    /* Public helper function that will check whether the chosen move was invalid */
        bool isInvalidMove();
    private:
    /* Private helper function that returns the location of 0 */
        int getZeroPosition();  
};

// NOT A PART OF THE CLASS: Function that will check whether current state is goal state
        bool isGoalState(vector<int> state);

#endif