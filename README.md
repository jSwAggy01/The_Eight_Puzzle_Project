# Project 1 - The Eight Puzzle

State representation will be a vector

Initial states will be arbitrary

Goal state will be a vector s.t. <1,2,3,4,5,6,7,8,0> is the final solution
Think of <a11,a12,a13,a21,a22,a23,a31,a32,a33> as being represented by a 3x3 matrix 

        a11 a12 a13             1   2   3
        a21 a22 a23     =>      4   5   6
        a31 a32 a33             7   8   0

   **Rememeber that the indices go from (0-8) for a 3x3 puzzle


The operators will be to move 0:
        - Left
        - Right
        - Up
        - Down
