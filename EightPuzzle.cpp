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
        int zeroPosition = getZeroPosition();

        if (zeroPosition == 0 || zeroPosition == 3 || zeroPosition == 7) {
            cout << "\n**Invalid move**\n\n";
            invalidMove = true;
        }
        else {
            int zeroFormerPosition = getZeroPosition();
            int temp = currentState.at(zeroFormerPosition);
            currentState.at(zeroFormerPosition) = currentState.at(zeroFormerPosition - 1);
            currentState.at(zeroFormerPosition - 1) = temp;
        }
    }

    void EightPuzzle::move_right() {
        int zeroPosition = getZeroPosition();

        if (zeroPosition == 2 || zeroPosition == 5 || zeroPosition == 8) {
            cout << "\n**Invalid move**\n\n";
            invalidMove = true;
        }
        else {
            int zeroFormerPosition = getZeroPosition();
            int temp = currentState.at(zeroFormerPosition);
            currentState.at(zeroFormerPosition) = currentState.at(zeroFormerPosition + 1);
            currentState.at(zeroFormerPosition + 1) = temp;
        }
    }

    void EightPuzzle::move_up() {
        int zeroPosition = getZeroPosition();

        if (zeroPosition == 0 || zeroPosition == 1 || zeroPosition == 2) {
            cout << "\n**Invalid move**\n\n";
            invalidMove = true;
        }
        else {
            int zeroFormerPosition = getZeroPosition();
            int temp = currentState.at(zeroFormerPosition);
            currentState.at(zeroFormerPosition) = currentState.at(zeroFormerPosition - 3);
            currentState.at(zeroFormerPosition - 3) = temp;
        }
    }

    void EightPuzzle::move_down() {
        int zeroPosition = getZeroPosition();

        if (zeroPosition == 6 || zeroPosition == 7 || zeroPosition == 8) {
            cout << "\n**Invalid move**\n\n";
            invalidMove = true;
        }
        else {
            int zeroFormerPosition = getZeroPosition();
            int temp = currentState.at(zeroFormerPosition);
            currentState.at(zeroFormerPosition) = currentState.at(zeroFormerPosition + 3);
            currentState.at(zeroFormerPosition + 3) = temp;
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
        cout << "\n\n";
    }

/* Prints whether current state is goal state */
    void EightPuzzle::outputCurrentStateStatus() {
        if (isGoalState()) {
            cout << "\n***SOLVED***\n\n";
        }
        else {
            cout << "\n***NOT SOLVED***\n\n";
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

/* Public helper function that will check whether the chosen move was invalid */
    bool EightPuzzle::isInvalidMove() {
        if (invalidMove) {
            return true;
        }
        return false;
    }

/* Public helper function that returns the index of where specified number is supposed to be */
    int EightPuzzle::getNumberPosition(int num) {
        int correctElement = 0;

        for (int i = 0; i < 8; ++i) {
            correctElement = i + 1;
            if (correctElement == num) {
                return i;
            }
        }

        cout << "***ERROR: '" << num << "' NOT FOUND***\n\n";
        return -1;  // This just ensures you get an out_of_range error
    }

/* Private helper function that returns location of 0 */
    int EightPuzzle::getZeroPosition() {
        for (int i = 0; i < currentState.size(); ++i) {
            if (currentState.at(i) == 0) {
                return i;
            }
        }
        cout << "***ERROR: '0' NOT FOUND***\n\n";
        return -1;  // This just ensures you get an out_of_range error
    }

// NOT A PART OF THE CLASS: Function that will check whether current state is goal state
    bool isGoalState(vector<int> state) {
        for (int i = 0; i < 8; ++i) {
            if (state.at(i) != i + 1) {
                return false;
            }
        }
        return true;
    }