#include <iostream>
#include <vector>
#include "EightPuzzle.h"
// Compile with: g++ EightPuzzle.cpp main.cpp -o ./a.exe

using namespace std;

int main() {

    cout << "\nBEGINNING TESTS...\n\n";

    cout << "Testing constructors, output function, puzzle status, and operators\n\n";
    {
        cout << "EXAMPLE #1:\n";
        cout << "Calling default constructor\n";
        EightPuzzle example1;
        cout << "Calling output function\n";
        example1.outputCurrentState();
        cout << "Calling puzzle status\n";
        example1.outputCurrentStateStatus();
        cout << "Move right\n";
        example1.move_right(); // Should output invalid move
        cout << "Calling output function\n";
        example1.outputCurrentState();
        cout << "Move left\n";
        example1.move_left();
        cout << "Calling output function\n";
        example1.outputCurrentState();
        cout << "Move down\n";
        example1.move_down(); // Should output invalid move
        cout << "Calling output function\n";
        example1.outputCurrentState();
        cout << "Move up\n";
        example1.move_up();
        cout << "Calling output function\n";
        example1.outputCurrentState();
        cout << "Calling puzzle status\n";
        example1.outputCurrentStateStatus();
        
        cout << "EXAMPLE #2:\n";
        cout << "Initializing constructor with vector\n";
        vector<int> vect1{1,2,3,4,5,0,7,8,6};
        EightPuzzle example2(vect1);
        cout << "Calling output function\n";
        example2.outputCurrentState();
        cout << "Calling puzzle status\n";
        example2.outputCurrentStateStatus();
        cout << "Move down\n";
        example2.move_down();
        cout << "Calling output function\n";
        example2.outputCurrentState();
        cout << "Calling puzzle status\n";
        example2.outputCurrentStateStatus();
    }

    cout << "...END OF TESTS\n";

    return 0;
}