#include <iostream>
#include <vector>
#include "EightPuzzle.h"
#include "Algorithms.h"
// Compile with: g++ EightPuzzle.cpp Algorithms.cpp main.cpp -o ./a.exe

using namespace std;

int main() {

    cout << "\nBEGINNING TESTS...\n\n";

    // cout << "Testing constructors, output function, puzzle status, and operators\n\n";
    // {
    //     cout << "EXAMPLE #1:\n";
    //     cout << "Calling default constructor\n";
    //     EightPuzzle example1;
    //     cout << "Calling output function\n";
    //     example1.outputCurrentState();
    //     cout << "Calling puzzle status\n";
    //     example1.outputCurrentStateStatus();
    //     cout << "Move right\n";
    //     example1.move_right(); // Should output invalid move
    //     cout << "Calling output function\n";
    //     example1.outputCurrentState();
    //     cout << "Move left\n";
    //     example1.move_left();
    //     cout << "Calling output function\n";
    //     example1.outputCurrentState();
    //     cout << "Move down\n";
    //     example1.move_down(); // Should output invalid move
    //     cout << "Calling output function\n";
    //     example1.outputCurrentState();
    //     cout << "Move up\n";
    //     example1.move_up();
    //     cout << "Calling output function\n";
    //     example1.outputCurrentState();
    //     cout << "Calling puzzle status\n";
    //     example1.outputCurrentStateStatus();
        
    //     cout << "EXAMPLE #2:\n";
    //     cout << "Initializing constructor with vector\n";
    //     vector<int> vect1{1,2,3,4,5,0,7,8,6};
    //     EightPuzzle example2(vect1);
    //     cout << "Calling output function\n";
    //     example2.outputCurrentState();
    //     cout << "Calling puzzle status\n";
    //     example2.outputCurrentStateStatus();
    //     cout << "Move down\n";
    //     example2.move_down();
    //     cout << "Calling output function\n";
    //     example2.outputCurrentState();
    //     cout << "Calling puzzle status\n";
    //     example2.outputCurrentStateStatus();
    // }

    cout << "RUNNING ALGORITHM TESTS...\n\n";

    cout << "Testing uniform cost search\n\n";
    {
        cout << "TEST CASE #1:\n";
        cout << "Calling default constructor\n";
        EightPuzzle testCase1;
        cout << "Calling output function\n";
        testCase1.outputCurrentState();
        cout << "Running uniform cost search\n";
        EightPuzzle solution1 = UniformCostSearch(testCase1);
        cout << "Calling output function\n";
        solution1.outputCurrentState();
        cout << "Calling puzzle status\n";
        solution1.outputCurrentStateStatus();

        cout << "TEST CASE #2:\n";
        cout << "Initializing constructor with vector\n";
        vector<int> vect2{1,2,3,4,5,6,0,7,8};
        EightPuzzle testCase2(vect2);
        cout << "Calling output function\n";
        testCase2.outputCurrentState();
        cout << "Running uniform cost search\n";
        UniformCostSearch(testCase2);
        EightPuzzle solution2 = UniformCostSearch(testCase2);
        cout << "Calling output function\n";
        solution2.outputCurrentState();
        cout << "Calling puzzle status\n";
        solution2.outputCurrentStateStatus();

        /* Uniform cost search takes forever to find the solution for this */
        // cout << "TEST CASE #3:\n";
        // cout << "Initializing constructor with vector\n";
        // vector<int> vect3{1,2,3,5,0,6,4,7,8};
        // EightPuzzle testCase3(vect3);
        // cout << "Calling output function\n";
        // testCase3.outputCurrentState();
        // cout << "Running uniform cost search\n";
        // UniformCostSearch(testCase3);
        // EightPuzzle solution3 = UniformCostSearch(testCase2);
        // cout << "Calling output function\n";
        // solution3.outputCurrentState();
        // cout << "Calling puzzle status\n";
        // solution3.outputCurrentStateStatus();
    }

    cout << "...END OF TESTS\n";

    return 0;
}

// Compile with: g++ EightPuzzle.cpp Algorithms.cpp main.cpp -o ./a.exe