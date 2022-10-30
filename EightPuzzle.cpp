#include "EightPuzzle.h"

/* Constructors: */

    /* Initializes the 8-puzzle to be the goal state */
    EightPuzzle::EightPuzzle() {
        currentState = {1,2,3,4,5,6,7,8,0};
    }

    /* Initializes the 8-puzzle to be the input state */
    EightPuzzle::EightPuzzle(vector<int> inputState) {
        currentState = inputState;
    }

/* Operators: */
    void EightPuzzle::move_left() {
        if (getZeroPosition() == 0 || getZeroPosition() == 3 || getZeroPosition() == 7) {
            cout << "Invalid move\n\n";
        }
        else {
            int temp = currentState.at(getZeroPosition());
            currentState.at(getZeroPosition()) = currentState.at(getZeroPosition() - 1);
            currentState.at(getZeroPosition() - 1) = temp;
        }
    }

    void EightPuzzle::move_right() {
        if (getZeroPosition() == 2 || getZeroPosition() == 5 || getZeroPosition() == 8) {
            cout << "Invalid move\n\n";
        }
        else {
            int temp = currentState.at(getZeroPosition());
            currentState.at(getZeroPosition()) = currentState.at(getZeroPosition() + 1);
            currentState.at(getZeroPosition() + 1) = temp;
        }
    }

    void EightPuzzle::move_up() {
        if (getZeroPosition() == 0 || getZeroPosition() == 1 || getZeroPosition() == 2) {
            cout << "Invalid move\n\n";
        }
        else {
            int temp = currentState.at(getZeroPosition());
            currentState.at(getZeroPosition()) = currentState.at(getZeroPosition() - 3);
            currentState.at(getZeroPosition() - 3) = temp;
        }
    }

    void EightPuzzle::move_down() {
        if (getZeroPosition() == 6 || getZeroPosition() == 7 || getZeroPosition() == 8) {
            cout << "Invalid move\n\n";
        }
        else {
            int temp = currentState.at(getZeroPosition());
            currentState.at(getZeroPosition()) = currentState.at(getZeroPosition() + 3);
            currentState.at(getZeroPosition() + 3) = temp;
        }
    }

/* Prints the current state in 3x3 representation */
    void EightPuzzle::outputCurrentState() {
        for (int i = 0; i < currentState.size(); ++i) {
            int j = i;

            if (j % 3 == 0) {
                j = 0;
                cout << endl;
            }

            cout << currentState.at(i) << " ";
        }
    }

/* Prints whether current state is goal state */
    void EightPuzzle::outputCurrentStateStatus() {
        if (isGoalState()) {
            cout << "\n***SOLVED***\n";
        }
        else {
            cout << "\n***NOT SOLVED***\n";
        }
    }

/* Public helper function that will check whether current state is goal state */
    bool EightPuzzle::isGoalState() {
        for (int i = 0; i < currentState.size() - 1; ++i) {
            if (currentState.at(i) != i + 1) {
                return false;
            }
        }
        return true;
    }

/* Private helper function that returns location of 0 */
    int EightPuzzle::getZeroPosition() {
        for (int i = 0; i < currentState.size(); ++i) {
            if (currentState.at(i) == 0) {
                return i;
            }
        }
        return 1;
    }