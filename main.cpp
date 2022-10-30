#include <iostream>
#include <vector>
#include "EightPuzzle.h"
// Compile with: g++ EightPuzzle.cpp main.cpp -o ./a.exe

using namespace std;

int main() {

    cout << "\nBeginning tests...\n\n";
    {
        cout << "Testing default constructor\n";
        EightPuzzle example1;
        cout << "Testing output function\n";
        example1.outputCurrentState();
        cout << "\n\nTesting puzzle status\n";
        example1.outputCurrentStateStatus();

        cout << "\nTesting initialized constructor\n";
        vector<int> vect1{1,2,3,4,0,6,7,8,5};
        EightPuzzle example2(vect1);
        cout << "Testing output function\n";
        example2.outputCurrentState();
        cout << "\n\nTesting puzzle status\n";
        example2.outputCurrentStateStatus();
    }

    cout << "\n\n...end of tests\n";

    return 0;
}